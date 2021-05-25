#include "boardview.h"
#include <QColor>
#include <QGraphicsTextItem>

#include "buildingview.h"
#include "setbuilding.h"
#include "setbonusview.h"
#include "dicebonusview.h"
#include "pickbonusview.h"
#include "cardbonusview.h"
#include "miscbonusview.h"
#include "toolbonusview.h"
#include "rollbonusview.h"
BoardView::BoardView()
{
}

void BoardView::newBuild(std::shared_ptr<Building> building, int pos){
    m_buildings[pos]->updateBuilding(building);
    if(building){
        connect(m_board->getOpenBuildingCard(pos).get(), &Building::changedWorkers,  m_buildings[pos].get(), &BuildingView::updateText);
        connect(m_board->getOpenBuildingCard(pos).get(), &Building::turnHappend,  this, &BoardView::updateTurn);
    }
}

void BoardView::updateTurn(){
    emit unHighlight(m_board->getCurrentPlayer());
    m_board->nextPlayer();
    emit highlight(m_board->getCurrentPlayer());
}

void BoardView::placementDone(){
    m_placementDone = true;
}

void BoardView::updateResources(){
    setSelectable(false);
    for(int i = (int)m_board->getCurrentPlayer(); i < (int)m_board->getCurrentPlayer() + 4; ++i){
        m_board->payResources((Colour)(i % 4));
        emit unHighlight((Colour)(i % 4));
        emit highlight((Colour)((i+1)%4));
    }
    m_board->resetWorkers();
    buildBuildings();
    m_board->feedWorkers();
    m_board->addRound();
}

void BoardView::buildBuildings(){
    for(int i = (int)m_board->getCurrentPlayer(); i < (int)m_board->getCurrentPlayer() + 4; ++i){
        m_board->buildBuilding((Colour)(i % 4));
        if(m_board->getEnded())
            return;
        emit unHighlight((Colour)(i % 4));
        emit highlight((Colour)((i+1)%4));
    }
    emit unHighlight(m_board->getCurrentPlayer());
    emit highlight((Colour)(((int)m_board->getCurrentPlayer() + 1) % 4));
    if(m_board->checkStacks()){
        m_board->end();
    }
    setSelectable(true);
    m_placementDone = false;
}

BoardView::BoardView(std::shared_ptr<Board> board, QObject* parent)
    : QGraphicsScene(parent), m_placementDone{false}, m_workeradd{std::make_unique<WorkerAdd>()}, m_board{board}{
    connect(m_board.get(), &Board::allWorkersPlaced, this, &BoardView::placementDone);
    int moveByX = 0;
    int rectWidth = 300;
    m_food = std::make_unique<ResourcePlaceView>(QColor(60,125,0), "Hunt", moveByX, m_board->getGather(Resource::food), this);//forest green
    connect(m_board->getGather(Resource::food).get(), &Place::changedWorkers, m_food.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::food).get(), &Place::turnHappend, this, &BoardView::updateTurn);
    //    connect(m_board.get(), &Board::workersReset, m_food.get(), &ResourcePlaceView::updateText);
    moveByX += rectWidth;
    m_wood = std::make_unique<ResourcePlaceView>(QColor(115,75,0), "Forest", moveByX, m_board->getGather(Resource::wood), this);//brown
    connect(m_board->getGather(Resource::wood).get(), &Place::changedWorkers, m_wood.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::wood).get(), &Place::turnHappend, this, &BoardView::updateTurn);
    //    connect(m_board.get(), &Board::workersReset, m_wood.get(), &ResourcePlaceView::updateText);
    moveByX += rectWidth;
    m_clay = std::make_unique<ResourcePlaceView>(QColor(220,85,57), "Clay Pit", moveByX, m_board->getGather(Resource::clay), this);//brick red
    connect(m_board->getGather(Resource::clay).get(), &Place::changedWorkers, m_clay.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::clay).get(), &Place::turnHappend, this, &BoardView::updateTurn);
    connect(m_board.get(), &Board::workersReset, m_clay.get(), &ResourcePlaceView::updateText);
    moveByX += rectWidth;
    m_stone = std::make_unique<ResourcePlaceView>(QColor(75,75,75), "Quarry", moveByX, m_board->getGather(Resource::stone), this);//grey
    connect(m_board->getGather(Resource::stone).get(), &Place::changedWorkers, m_stone.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::stone).get(), &Place::turnHappend, this, &BoardView::updateTurn);
    //    connect(m_board.get(), &Board::workersReset, m_stone.get(), &ResourcePlaceView::updateText);
    moveByX += rectWidth;
    m_gold = std::make_unique<ResourcePlaceView>(QColor(255,215,0), "River", moveByX, m_board->getGather(Resource::gold), this);//gold
    connect(m_board->getGather(Resource::gold).get(), &Place::changedWorkers, m_gold.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::gold).get(), &Place::turnHappend, this, &BoardView::updateTurn);
    //    connect(m_board.get(), &Board::workersReset, m_gold.get(), &ResourcePlaceView::updateText);

    moveByX = 0;
    rectWidth = 500;
    m_field = std::make_unique<OtherPlaceView>(QColor(245,222,179), moveByX, 1, "Field", m_board->getField(), this);//wheat yellow
    connect(m_board->getField().get(), &Place::changedWorkers, m_field.get(), &OtherPlaceView::updateText);
    connect(m_board->getField().get(), &Place::turnHappend, this, &BoardView::updateTurn);
    //    connect(m_board.get(), &Board::workersReset, m_field.get(), &OtherPlaceView::updateText);
    moveByX += rectWidth;
    m_hut = std::make_unique<OtherPlaceView>(QColor(254,184,198), moveByX, 2, "Hut", m_board->getHut(), this);//love pink
    connect(m_board->getHut().get(), &Place::changedWorkers, m_hut.get(), &OtherPlaceView::updateText);
    connect(m_board->getHut().get(), &Place::turnHappend, this, &BoardView::updateTurn);
    //    connect(m_board.get(), &Board::workersReset, m_hut.get(), &OtherPlaceView::updateText);
    moveByX += rectWidth;
    m_toolshed = std::make_unique<OtherPlaceView>(QColor(161,133,105), moveByX, 1, "Tool Shed", m_board->getToolShed(), this);//tool brown
    connect(m_board->getToolShed().get(), &Place::changedWorkers, m_toolshed.get(), &OtherPlaceView::updateText);
    connect(m_board->getToolShed().get(), &Place::turnHappend, this, &BoardView::updateTurn);
    //    connect(m_board.get(), &Board::workersReset, m_toolshed.get(), &OtherPlaceView::updateText);

    moveByX = 0;
    rectWidth = 175;
    for(int i = 0; i < 4; ++i){
        m_buildings[i] = std::make_unique<BuildingView>(moveByX, m_board->getOpenBuildingCard(i), this);
        moveByX += rectWidth;
        connect(m_board->getOpenBuildingCard(i).get(), &Building::changedWorkers,  m_buildings[i].get(), &BuildingView::updateText);
        connect(m_board->getOpenBuildingCard(i).get(), &Building::turnHappend,  this, &BoardView::updateTurn);
    }
     moveByX += 100;
    for(int i = 0; i < 4; ++i){
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
//        connect(m_board->getOpenBuildingCard(i).get(), &Building::changedWorkers,  m_buildings[i].get(), &BuildingView::updateText);
//        connect(m_board->getOpenBuildingCard(i).get(), &Building::turnHappend,  this, &BoardView::updateTurn);
    }
    connect(m_board.get(), &Board::newBuild, this, &BoardView::newBuild);

}

void BoardView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mouseReleaseEvent(event);
    QList<QGraphicsItem*>list = this->selectedItems();
    if(list.length() == 0)
        return;
    ResourcePlaceView* resourceSelected = dynamic_cast<ResourcePlaceView*>(list[0]);
    if(resourceSelected){
        m_workeradd->setDynamic();
        m_workeradd->addToPlace(resourceSelected->getPlace(), m_board->getPlayer(m_board->getCurrentPlayer()));
        m_workeradd->exec();
    }
    OtherPlaceView* otherSelected = dynamic_cast<OtherPlaceView*>(list[0]);
    if(otherSelected){
        m_workeradd->setStatic(otherSelected->getCost());
        m_workeradd->addToPlace(otherSelected->getPlace(), m_board->getPlayer(m_board->getCurrentPlayer()));
        m_workeradd->exec();
    }
    BuildingView* buildingSelected = dynamic_cast<BuildingView*>(list[0]);
    if(buildingSelected){
        m_workeradd->setStatic(1);
        if(buildingSelected->getBuilding()){
            m_workeradd->addToBuilding(buildingSelected->getBuilding(), m_board->getPlayer(m_board->getCurrentPlayer()));
            m_workeradd->exec();
        }
    }
    if(m_placementDone){
        updateResources();
    }
}

void BoardView::setSelectable(bool isSelectalbe){
    if(isSelectalbe){
        m_food->setFlag(QGraphicsItem::ItemIsSelectable, true);
        m_wood->setFlag(QGraphicsItem::ItemIsSelectable, true);
        m_clay->setFlag(QGraphicsItem::ItemIsSelectable, true);
        m_stone->setFlag(QGraphicsItem::ItemIsSelectable, true);
        m_gold->setFlag(QGraphicsItem::ItemIsSelectable, true);
        m_field->setFlag(QGraphicsItem::ItemIsSelectable, true);
        m_hut->setFlag(QGraphicsItem::ItemIsSelectable, true);
        m_toolshed->setFlag(QGraphicsItem::ItemIsSelectable, true);
        for(int i = 0; i<4; ++i){
            m_buildings[i]->setFlag(QGraphicsItem::ItemIsSelectable, true);
        }
    }else{
        m_food->setFlag(QGraphicsItem::ItemIsSelectable, false);
        m_wood->setFlag(QGraphicsItem::ItemIsSelectable, false);
        m_clay->setFlag(QGraphicsItem::ItemIsSelectable, false);
        m_stone->setFlag(QGraphicsItem::ItemIsSelectable, false);
        m_gold->setFlag(QGraphicsItem::ItemIsSelectable, false);
        m_field->setFlag(QGraphicsItem::ItemIsSelectable, false);
        m_hut->setFlag(QGraphicsItem::ItemIsSelectable, false);
        m_toolshed->setFlag(QGraphicsItem::ItemIsSelectable, false);
        for(int i = 0; i<4; ++i){
            m_buildings[i]->setFlag(QGraphicsItem::ItemIsSelectable, false);
        }
    }
}
