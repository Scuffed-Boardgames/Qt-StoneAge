#include "boardview.h"
#include <QColor>
#include <QGraphicsTextItem>

#include "buildingview.h"
#include "setbuilding.h"

BoardView::BoardView()
{
}

void BoardView::newBuild(std::shared_ptr<Building> building, int pos){
    m_buildings[pos]->updateBuilding(building.get());
    connect(m_board->getOpenBuildingCard(pos).get(), &Building::changedWorkers,  m_buildings[pos].get(), &BuildingView::updateText);

}

void BoardView::updateTurn()
{
    m_board->nextPlayer();
}

void BoardView::startPayout()
{
    setSelectable(false);
    for(int i = 0; i<4; ++i){
        m_board->payResources((Colour)i);
    }
    m_board->resetWorkers();
    setSelectable(true);
}

BoardView::BoardView(std::shared_ptr<Board> board, QObject* parent) : QGraphicsScene(parent), m_workeradd{std::make_unique<WorkerAdd>()}, m_board{board}
{
    connect(m_board.get(), &Board::allWorkersPlaced, this, &BoardView::startPayout);
    int moveByX = 50;
    int rectWidth = 300;
    m_food = std::make_unique<ResourcePlaceView>(QColor(60,125,0), "Hunt", moveByX, m_board->getGather(Resource::food), this);//forest green
    connect(m_board->getGather(Resource::food), &Place::changedWorkers, m_food.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::food), &Place::turnHappend, this, &BoardView::updateTurn);
    moveByX += rectWidth;
    m_wood = std::make_unique<ResourcePlaceView>(QColor(115,75,0), "Forest", moveByX, m_board->getGather(Resource::wood), this);//brown
    connect(m_board->getGather(Resource::wood), &Place::changedWorkers, m_wood.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::wood), &Place::turnHappend, this, &BoardView::updateTurn);
    moveByX += rectWidth;
    m_clay = std::make_unique<ResourcePlaceView>(QColor(220,85,57), "Clay Pit", moveByX, m_board->getGather(Resource::clay), this);//brick red
    connect(m_board->getGather(Resource::clay), &Place::changedWorkers, m_clay.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::clay), &Place::turnHappend, this, &BoardView::updateTurn);
    moveByX += rectWidth;
    m_stone = std::make_unique<ResourcePlaceView>(QColor(75,75,75), "Quarry", moveByX, m_board->getGather(Resource::stone), this);//grey
    connect(m_board->getGather(Resource::stone), &Place::changedWorkers, m_stone.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::stone), &Place::turnHappend, this, &BoardView::updateTurn);
    moveByX += rectWidth;
    m_gold = std::make_unique<ResourcePlaceView>(QColor(255,215,0), "River", moveByX, m_board->getGather(Resource::gold), this);//gold
    connect(m_board->getGather(Resource::gold), &Place::changedWorkers, m_gold.get(), &ResourcePlaceView::updateText);
    connect(m_board->getGather(Resource::gold), &Place::turnHappend, this, &BoardView::updateTurn);

    moveByX = 50;
    rectWidth = 500;
    m_field = std::make_unique<OtherPlaceView>(QColor(245,222,179), moveByX, 1, "Field", nullptr, this);//wheat yellow
    moveByX += rectWidth;
    m_hut = std::make_unique<OtherPlaceView>(QColor(254,184,198), moveByX, 2, "Hut", nullptr, this);//love pink
    moveByX += rectWidth;
    m_toolshed = std::make_unique<OtherPlaceView>(QColor(161,133,105), moveByX, 1, "Tool Shed", m_board->getToolShed(), this);//tool brown
    connect(m_board->getToolShed(), &Place::changedWorkers, m_toolshed.get(), &OtherPlaceView::updateText);

    moveByX = 50;
    rectWidth = 175;
    for(int i = 0; i < 4; ++i){
        m_buildings[i] = std::make_unique<BuildingView>(moveByX, m_board->getOpenBuildingCard(i).get(), this);
        moveByX += rectWidth;
        connect(m_board->getOpenBuildingCard(i).get(), &Building::changedWorkers,  m_buildings[i].get(), &BuildingView::updateText);
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
        m_workeradd->show();
        return;
    }
    OtherPlaceView* otherSelected = dynamic_cast<OtherPlaceView*>(list[0]);
    if(otherSelected){
        m_workeradd->setStatic(otherSelected->getCost());
        m_workeradd->addToPlace(otherSelected->getPlace(), m_board->getPlayer(m_board->getCurrentPlayer()));
        m_workeradd->show();
        return;
    }
    BuildingView* buildingSelected = dynamic_cast<BuildingView*>(list[0]);
    if(buildingSelected){
         m_workeradd->setStatic(1);
         m_workeradd->addToBuilding(buildingSelected->getBuilding(), m_board->getPlayer(m_board->getCurrentPlayer()));
         m_workeradd->show();
         return;
    }
}

void BoardView::setSelectable(bool isSelectalbe)
{
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
