#include "boardview.h"
#include"placeview.h"
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
    m_food = std::make_unique<PlaceView>(QColor(60,125,0), "Food", moveByX, this);//forest green
    moveByX += rectWidth;
    m_wood = std::make_unique<PlaceView>(QColor(115,75,0), "Wood", moveByX, this);//brown
    moveByX += rectWidth;
    m_clay = std::make_unique<PlaceView>(QColor(220,85,57), "Clay", moveByX, this);//brick red
    moveByX += rectWidth;
    m_stone = std::make_unique<PlaceView>(QColor(75,75,75), "Stone", moveByX, this);//grey
    moveByX += rectWidth;
    m_gold = std::make_unique<PlaceView>(QColor(255,215,0), "Gold", moveByX, this);//gold
    moveByX = 50;
    rectWidth = 500;
    makeSmallPlace(QColor(245,222,179), moveByX, 210, "Field");//wheat yellow 210
    moveByX += rectWidth;
    makeSmallPlace(QColor(254,184,198), moveByX, 210, "Hut");//love pink 210
    moveByX += rectWidth;
    makeSmallPlace(QColor(161,133,105), moveByX, 180, "Tool Shed" );//tool brown 180
    m_workeradd = std::make_unique<WorkerAdd>();

}

QGraphicsRectItem* BoardView::makeSmallPlace(QColor colour, int moveByX,int textMoveX, QString name){
    QBrush brushwhite;
    brushwhite.setColor(QColor(234,222,210)); //white
    brushwhite.setStyle(Qt::SolidPattern);

    QBrush brush;
    brush.setColor(colour);
    brush.setStyle(Qt::SolidPattern);

    QGraphicsRectItem* tile = new QGraphicsRectItem(0, 0,500,400);
    tile->moveBy(moveByX,500);
    tile->setBrush(brush);
    this->addItem(tile);

    QFont font("Font", 26);
    QGraphicsTextItem* text = new QGraphicsTextItem(name, tile);
    text->setFont(font);
    text->moveBy(textMoveX,50);//210/180

    QGraphicsRectItem* child;
    child = new QGraphicsRectItem(0, 0,300,200, tile);
    child->moveBy(100,150);
    child->setBrush(brushwhite);
//    return child;
    return tile;
}
void BoardView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mouseReleaseEvent(event);
    QList<QGraphicsItem*>list = this->selectedItems();
    if(list.length() == 0)
        return;
    m_workeradd->addToPlace((PlaceView*)list[0], m_activeColour);
    m_workeradd->show();
}
