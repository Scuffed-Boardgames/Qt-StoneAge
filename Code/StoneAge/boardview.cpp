#include "boardview.h"
#include "buildingview.h"
#include "setbuilding.h"
#include "setbonusview.h"
#include "dicebonusview.h"
#include "pickbonusview.h"
#include "cardbonusview.h"
#include "miscbonusview.h"
#include "toolbonusview.h"
#include "rollbonusview.h"


BoardView::BoardView(std::shared_ptr<Board> board, QObject* parent)
    : QGraphicsScene(parent), m_placementDone{false}, m_board{board}{
    connect(m_board.get(), &Board::allWorkersPlaced, this, &BoardView::placementDone);
    int moveByX = 0;
    int rectWidth = 300;
    m_food = std::make_unique<ResourcePlaceView>(QColor(60,125,0), "Hunt", moveByX, m_board->getGather(Resource::food), this);//forest green
    connect(m_board->getGather(Resource::food).get(), &Place::changedWorkers, m_food.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::food).get(), &Place::turnHappend, this, &BoardView::updateTurn);

    moveByX += rectWidth;
    m_wood = std::make_unique<ResourcePlaceView>(QColor(115,75,0), "Forest", moveByX, m_board->getGather(Resource::wood), this);//brown
    connect(m_board->getGather(Resource::wood).get(), &Place::changedWorkers, m_wood.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::wood).get(), &Place::turnHappend, this, &BoardView::updateTurn);

    moveByX += rectWidth;
    m_clay = std::make_unique<ResourcePlaceView>(QColor(220,85,57), "Clay Pit", moveByX, m_board->getGather(Resource::clay), this);//brick red
    connect(m_board->getGather(Resource::clay).get(), &Place::changedWorkers, m_clay.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::clay).get(), &Place::turnHappend, this, &BoardView::updateTurn);
    connect(m_board.get(), &Board::workersReset, m_clay.get(), &ResourcePlaceView::updateText);

    moveByX += rectWidth;
    m_stone = std::make_unique<ResourcePlaceView>(QColor(75,75,75), "Quarry", moveByX, m_board->getGather(Resource::stone), this);//grey
    connect(m_board->getGather(Resource::stone).get(), &Place::changedWorkers, m_stone.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::stone).get(), &Place::turnHappend, this, &BoardView::updateTurn);

    moveByX += rectWidth;
    m_gold = std::make_unique<ResourcePlaceView>(QColor(255,215,0), "River", moveByX, m_board->getGather(Resource::gold), this);//gold
    connect(m_board->getGather(Resource::gold).get(), &Place::changedWorkers, m_gold.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::gold).get(), &Place::turnHappend, this, &BoardView::updateTurn);

    moveByX = 0;
    rectWidth = 500;
    m_field = std::make_unique<OtherPlaceView>(QColor(245,222,179), moveByX, 1, "Field", m_board->getField(), this);//wheat yellow
    connect(m_board->getField().get(), &Place::changedWorkers, m_field.get(), &OtherPlaceView::updateText);
    connect(m_board->getField().get(), &Place::turnHappend, this, &BoardView::updateTurn);

    moveByX += rectWidth;
    m_hut = std::make_unique<OtherPlaceView>(QColor(254,184,198), moveByX, 2, "Hut", m_board->getHut(), this);//love pink
    connect(m_board->getHut().get(), &Place::changedWorkers, m_hut.get(), &OtherPlaceView::updateText);
    connect(m_board->getHut().get(), &Place::turnHappend, this, &BoardView::updateTurn);

    moveByX += rectWidth;
    m_toolshed = std::make_unique<OtherPlaceView>(QColor(161,133,105), moveByX, 1, "Tool Shed", m_board->getToolShed(), this);//tool brown
    connect(m_board->getToolShed().get(), &Place::changedWorkers, m_toolshed.get(), &OtherPlaceView::updateText);
    connect(m_board->getToolShed().get(), &Place::turnHappend, this, &BoardView::updateTurn);

    moveByX = 0;
    rectWidth = 175;
    for(int i = 0; i < 4; ++i){
        m_buildings[i] = std::make_unique<BuildingView>(moveByX, m_board->getOpenBuildingCard(i), 7, this);
        moveByX += rectWidth;
        connect(m_board->getOpenBuildingCard(i).get(), &Building::changedWorkers,  m_buildings[i].get(), &BuildingView::updateText);
        connect(m_board->getOpenBuildingCard(i).get(), &Building::turnHappend,  this, &BoardView::updateTurn);
    }
    QGraphicsRectItem* AmountHolder = new QGraphicsRectItem(0,0,100,100, m_buildings[3].get());
    AmountHolder->moveBy(rectWidth, 0);
    AmountHolder->setBrush(Qt::gray);
    m_civCardAmount = new QGraphicsTextItem("32", AmountHolder);
    m_civCardAmount->setFont(QFont("Arial", 26));
    m_civCardAmount->moveBy(25, 25);
    updateCivCards(32);
    connect(m_board.get(), &Board::newBuild, this, &BoardView::newBuild);
    connect(m_board.get(), &Board::newCiv, this, &BoardView::updateCivCards);
}

void BoardView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mouseReleaseEvent(event);
    QList<QGraphicsItem*>list = this->selectedItems();
    if (list.length() == 0)
        return;
    if (ResourcePlaceView* resourceSelected = dynamic_cast<ResourcePlaceView*>(list[0])){
        WorkerAdd workerAdd;
        workerAdd.addToPlace(resourceSelected->getPlace(), m_board->getPlayer(m_board->getCurrentPlayer()));
        workerAdd.exec();
    }else if (OtherPlaceView* otherSelected = dynamic_cast<OtherPlaceView*>(list[0])){
        WorkerAdd workerAdd;
        workerAdd.setStatic(otherSelected->getCost());
        workerAdd.addToPlace(otherSelected->getPlace(), m_board->getPlayer(m_board->getCurrentPlayer()));
        workerAdd.exec();
    }else if (BuildingView* buildingSelected = dynamic_cast<BuildingView*>(list[0])){
        WorkerAdd workerAdd;
        workerAdd.setStatic(1);
        if(buildingSelected->getBuilding()){
            workerAdd.addToBuilding(buildingSelected->getBuilding(), m_board->getPlayer(m_board->getCurrentPlayer()));
            workerAdd.exec();
        }
    }else if (CivilisationView* civSelected = dynamic_cast<CivilisationView*>(list[0])){
        WorkerAdd workerAdd;
        workerAdd.setStatic(1);
        workerAdd.addToCiv(civSelected->getCivilisation(), m_board->getPlayer(m_board->getCurrentPlayer()));
        workerAdd.exec();
    }
    if(m_placementDone){
        gameLoop();
    }
}

void BoardView::newBuild(std::shared_ptr<Building> building, int pos, int stackSize){
    m_buildings[pos]->updateBuilding(building, stackSize);
    if(building){
        connect(m_board->getOpenBuildingCard(pos).get(), &Building::changedWorkers,  m_buildings[pos].get(), &BuildingView::updateText);
        connect(m_board->getOpenBuildingCard(pos).get(), &Building::turnHappend,  this, &BoardView::updateTurn);
    }
}


void BoardView::updateTurn(){
    emit unHighlight(m_board->getCurrentPlayer());
    m_board->nextPlayer();
    emit highlight(m_board->getCurrentPlayer());
    m_board->checkChosen(m_board->getCurrentPlayer());
}

void BoardView::placementDone(){
    m_placementDone = true;
}

void BoardView::gameLoop(){
    setSelectable(false);
    for(int i = (int)m_board->getCurrentPlayer(); i < (int)m_board->getCurrentPlayer() + 4; ++i){
        m_board->checkChosen((Colour)(i % 4));
        m_board->payResources((Colour)(i % 4));
        m_board->resetWorkers((Colour)(i % 4));
        m_board->civilizeCivilisation((Colour)(i % 4));
        m_board->checkChosen((Colour)(i % 4));
        m_board->buildBuilding((Colour)(i % 4));
        m_board->getPlayer((Colour)(i % 4))->resetTools();
        emit unHighlight((Colour)(i % 4));
        emit highlight((Colour)((i+1)%4));
    }

    for(int i = (int)m_board->getCurrentPlayer(); i < (int)m_board->getCurrentPlayer() + 4; ++i){
        m_board->feedWorkers((Colour)(i % 4));
        emit unHighlight((Colour)(i % 4));
        emit highlight((Colour)((i+1)%4));
    }


    emit unHighlight(m_board->getCurrentPlayer());
    emit highlight((Colour)(((int)m_board->getCurrentPlayer() + 1) % 4));
    m_board->addRound();
     m_board->checkChosen(m_board->getCurrentPlayer());
    int stackSize = m_board->newCivCards();

    if(m_board->checkStacks()){
        m_board->end();
    }

    if(m_board->getEnded()){
        emit endGame();
        return;
    }
    updateCivCards(stackSize);
    setSelectable(true);
    m_placementDone = false;
}

void BoardView::updateCivCards(int stackSize){
    m_civCardAmount->setPlainText(QString::number(stackSize));
    int moveByX = 800;
    int rectWidth = 175;
    for(int i = 0; i < 4; ++i){
        disconnect(m_board->getOpenCivilisationCard(i).get(), &Civilisation::changedWorkers, m_civilisations[i].get(), &CivilisationView::updateText);
        disconnect(m_board->getOpenCivilisationCard(i).get(), &Civilisation::turnHappend, this, &BoardView::updateTurn);
        this->removeItem(m_civilisations[i].get());
        m_civilisations[i].release();
        if(std::dynamic_pointer_cast<SetBonus>(m_board->getOpenCivilisationCard(i))){
            m_civilisations[i] = std::make_unique<SetBonusView>(moveByX, m_board->getOpenCivilisationCard(i), this);
        } else if(std::dynamic_pointer_cast<DiceBonus>(m_board->getOpenCivilisationCard(i))){
            m_civilisations[i] = std::make_unique<DiceBonusView>(moveByX, m_board->getOpenCivilisationCard(i), this);
        } else if(std::dynamic_pointer_cast<PickBonus>(m_board->getOpenCivilisationCard(i))){
            m_civilisations[i] = std::make_unique<PickBonusView>(moveByX, m_board->getOpenCivilisationCard(i), this);
        } else if(std::dynamic_pointer_cast<CardBonus>(m_board->getOpenCivilisationCard(i))){
            m_civilisations[i] = std::make_unique<CardBonusView>(moveByX, m_board->getOpenCivilisationCard(i), this);
        } else if(std::dynamic_pointer_cast<MiscBonus>(m_board->getOpenCivilisationCard(i))){
            m_civilisations[i] = std::make_unique<MiscBonusView>(moveByX, m_board->getOpenCivilisationCard(i), this);
        } else if(std::dynamic_pointer_cast<ToolBonus>(m_board->getOpenCivilisationCard(i))){
            m_civilisations[i] = std::make_unique<ToolBonusView>(moveByX, m_board->getOpenCivilisationCard(i), this);
        } else if(std::dynamic_pointer_cast<RollBonus>(m_board->getOpenCivilisationCard(i))){
            m_civilisations[i] = std::make_unique<RollBonusView>(moveByX, m_board->getOpenCivilisationCard(i), this);
        } else{
            m_civilisations[i] = std::make_unique<CivilisationView>(moveByX, m_board->getOpenCivilisationCard(i), this);
        }
        moveByX += rectWidth;
        connect(m_board->getOpenCivilisationCard(i).get(), &Civilisation::changedWorkers, m_civilisations[i].get(), &CivilisationView::updateText);
        connect(m_board->getOpenCivilisationCard(i).get(), &Civilisation::turnHappend, this, &BoardView::updateTurn);
    }
}

void BoardView::setSelectable(bool isSelectalbe){
    m_food->setFlag(QGraphicsItem::ItemIsSelectable, isSelectalbe);
    m_wood->setFlag(QGraphicsItem::ItemIsSelectable, isSelectalbe);
    m_clay->setFlag(QGraphicsItem::ItemIsSelectable, isSelectalbe);
    m_stone->setFlag(QGraphicsItem::ItemIsSelectable, isSelectalbe);
    m_gold->setFlag(QGraphicsItem::ItemIsSelectable, isSelectalbe);
    m_field->setFlag(QGraphicsItem::ItemIsSelectable, isSelectalbe);
    m_hut->setFlag(QGraphicsItem::ItemIsSelectable, isSelectalbe);
    m_toolshed->setFlag(QGraphicsItem::ItemIsSelectable, isSelectalbe);
    for(int i = 0; i < 4; ++i){
        m_buildings[i]->setFlag(QGraphicsItem::ItemIsSelectable, isSelectalbe);
    }

}
