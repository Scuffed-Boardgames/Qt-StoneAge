#include "boardview.h"
#include <QColor>
#include <QGraphicsTextItem>

BoardView::BoardView()
{
}

BoardView::BoardView(std::shared_ptr<Board> board, QObject* parent) : QGraphicsScene(parent), m_activeColour{Colour::red}, m_workeradd{std::make_unique<WorkerAdd>()}, m_board{board}
{

    int moveByX = 50;
    int rectWidth = 300;
    m_food = std::make_unique<ResourcePlaceView>(QColor(60,125,0), "Hunt", moveByX, m_board->getGather(Resource::food), this);//forest green
    connect(m_board->getGather(Resource::food), &Place::changedWorkers, m_food.get(), &ResourcePlaceView::updateText);
    moveByX += rectWidth;
    m_wood = std::make_unique<ResourcePlaceView>(QColor(115,75,0), "Forest", moveByX, m_board->getGather(Resource::wood), this);//brown
    connect(m_board->getGather(Resource::wood), &Place::changedWorkers, m_wood.get(), &ResourcePlaceView::updateText);
    moveByX += rectWidth;
    m_clay = std::make_unique<ResourcePlaceView>(QColor(220,85,57), "Clay Pit", moveByX, m_board->getGather(Resource::clay), this);//brick red
    connect(m_board->getGather(Resource::clay), &Place::changedWorkers, m_clay.get(), &ResourcePlaceView::updateText);
    moveByX += rectWidth;
    m_stone = std::make_unique<ResourcePlaceView>(QColor(75,75,75), "Quarry", moveByX, m_board->getGather(Resource::stone), this);//grey
    connect(m_board->getGather(Resource::stone), &Place::changedWorkers, m_stone.get(), &ResourcePlaceView::updateText);
    moveByX += rectWidth;
    m_gold = std::make_unique<ResourcePlaceView>(QColor(255,215,0), "River", moveByX, m_board->getGather(Resource::gold), this);//gold
    connect(m_board->getGather(Resource::gold), &Place::changedWorkers, m_gold.get(), &ResourcePlaceView::updateText);

    moveByX = 50;
    rectWidth = 500;
    m_field = std::make_unique<OtherPlaceView>(QColor(245,222,179), moveByX, 1, "Field", nullptr, this);//wheat yellow
    moveByX += rectWidth;
    m_hut = std::make_unique<OtherPlaceView>(QColor(254,184,198), moveByX, 2, "Hut", nullptr, this);//love pink
    moveByX += rectWidth;
    m_toolshed = std::make_unique<OtherPlaceView>(QColor(161,133,105), moveByX, 1, "Tool Shed", m_board->getToolShed(), this);//tool brown
    connect(m_board->getToolShed(), &Place::changedWorkers, m_toolshed.get(), &OtherPlaceView::updateText);
}

void BoardView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mouseReleaseEvent(event);
    QList<QGraphicsItem*>list = this->selectedItems();
    if(list.length() == 0)
        return;
    ResourcePlaceView* resourceSelected = dynamic_cast<ResourcePlaceView*>(list[0]);
    if(resourceSelected){
        m_workeradd->setDynamic();
        m_workeradd->addToPlace(resourceSelected->getPlace(), m_board->getPlayer(m_activeColour));
        m_workeradd->show();
        return;
    }
    OtherPlaceView* otherSelected = dynamic_cast<OtherPlaceView*>(list[0]);
    if(otherSelected){
        m_workeradd->setStatic(otherSelected->getCost());
        m_workeradd->addToPlace(otherSelected->getPlace(), m_board->getPlayer(m_activeColour));
        m_workeradd->show();
        return;
    }
}
