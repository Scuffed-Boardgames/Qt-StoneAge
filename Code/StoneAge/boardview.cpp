#include "boardview.h"
#include <QColor>
#include <QGraphicsTextItem>

BoardView::BoardView()
{
}

BoardView::BoardView(std::shared_ptr<Board> board, QObject* parent) : QGraphicsScene(parent)
{
    m_board = board;
    m_activeColour = Colour::red;

    int moveByX = 50;
    int rectWidth = 300;
    m_food = std::make_unique<ResourcePlaceView>(QColor(60,125,0), "Food", moveByX, nullptr, this);//forest green
    moveByX += rectWidth;
    m_wood = std::make_unique<ResourcePlaceView>(QColor(115,75,0), "Wood", moveByX, nullptr, this);//brown
    moveByX += rectWidth;
    m_clay = std::make_unique<ResourcePlaceView>(QColor(220,85,57), "Clay", moveByX, nullptr, this);//brick red
    moveByX += rectWidth;
    m_stone = std::make_unique<ResourcePlaceView>(QColor(75,75,75), "Stone", moveByX, nullptr, this);//grey
    moveByX += rectWidth;
    m_gold = std::make_unique<ResourcePlaceView>(QColor(255,215,0), "Gold", moveByX, nullptr, this);//gold

    moveByX = 50;
    rectWidth = 500;
    m_field = std::make_unique<OtherPlaceView>(QColor(245,222,179), moveByX, 210, 1, "Field", this);//wheat yellow 210
    moveByX += rectWidth;
    m_hut = std::make_unique<OtherPlaceView>(QColor(254,184,198), moveByX, 210, 2, "Hut", this);//love pink 210
    moveByX += rectWidth;
    m_toolshed = std::make_unique<OtherPlaceView>(QColor(161,133,105), moveByX, 180, 1, "Tool Shed", this);//tool brown 180

    m_workeradd = std::make_unique<WorkerAdd>();

}

void BoardView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mouseReleaseEvent(event);
    QList<QGraphicsItem*>list = this->selectedItems();
    if(list.length() == 0)
        return;
    ResourcePlaceView* resourceSelected = dynamic_cast<ResourcePlaceView*>(list[0]);
    if(resourceSelected){
        m_workeradd->setDynamic();
        m_workeradd->addToPlace(resourceSelected, m_activeColour);
        m_workeradd->show();
        return;
    }
    OtherPlaceView* otherSelected = dynamic_cast<OtherPlaceView*>(list[0]);
    if(otherSelected){
        m_workeradd->setStatic(otherSelected->getCost());
        otherSelected->setColour(Colour::red);
        m_workeradd->show();
        return;
    }
}
