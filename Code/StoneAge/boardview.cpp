#include "boardview.h"
#include <QColor>
#include <QGraphicsTextItem>

BoardView::BoardView()
{
}

BoardView::BoardView(std::shared_ptr<Board> board) : QGraphicsScene()
{
    m_board = board;

    int moveByX = 50;
    int rectWidth = 300;
    makePlace(QColor(60,125,0), "Food", moveByX, &m_huntValues); //forest green
    moveByX += rectWidth;
    makePlace(QColor(115,75,0), "Wood", moveByX, &m_forestValues); //brown
    moveByX += rectWidth;
    makePlace(QColor(220,85,57), "Clay", moveByX, &m_claypitValues); //brick red
    moveByX += rectWidth;
    makePlace(QColor(75,75,75), "Stone", moveByX, &m_quarryValues); //grey
    moveByX += rectWidth;
    makePlace(QColor(255,215,0), "Gold", moveByX, &m_riverValues); //gold

    moveByX = 50;
    rectWidth = 500;
    makeSmallPlace(QColor(245,222,179), moveByX, 210, "Field");//wheat yellow 210
    moveByX += rectWidth;
    makeSmallPlace(QColor(254,184,198), moveByX, 210, "Hut");//love pink 210
    moveByX += rectWidth;
    makeSmallPlace(QColor(161,133,105), moveByX, 180, "Tool Shed" );//tool brown 180
}

QGraphicsRectItem* BoardView::makeSmallPlace(QColor colour, int moveByX,int textMoveX, QString name){
    QBrush brushwhite;
    brushwhite.setColor(QColor(234,222,210)); //white
    brushwhite.setStyle(Qt::SolidPattern);
    m_brushes.push_back(brushwhite);

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

void BoardView::makePlace(QColor colour, QString name, int moveByX, std::vector<QGraphicsTextItem*>* values){
    QBrush brushwhite;
    brushwhite.setColor(QColor(234,222,210)); //white
    brushwhite.setStyle(Qt::SolidPattern);
    m_brushes.push_back(brushwhite);
    QBrush brushred;
    brushred.setColor(QColor(237,28,36)); //red
    brushred.setStyle(Qt::SolidPattern);
    m_brushes.push_back(brushred);
    QBrush brushblue;
    brushblue.setColor(QColor(63,72,204)); //blue
    brushblue.setStyle(Qt::SolidPattern);
    m_brushes.push_back(brushblue);
    QBrush brushyellow;
    brushyellow.setColor(QColor(255,242,0)); //yellow
    brushyellow.setStyle(Qt::SolidPattern);
    m_brushes.push_back(brushyellow);
    QBrush brushgreen;
    brushgreen.setColor(QColor(34,177,76)); //green
    brushgreen.setStyle(Qt::SolidPattern);
    m_brushes.push_back(brushgreen);

    QBrush brushforestgreen;
    brushforestgreen.setColor(colour);
    brushforestgreen.setStyle(Qt::SolidPattern);
    int rectWidth = 300;

    QGraphicsRectItem* parent = new QGraphicsRectItem(0, 0,rectWidth,400);
    parent->moveBy(moveByX,100);
    parent->setBrush(colour);
    this->addItem(parent);

    QGraphicsTextItem* text = new QGraphicsTextItem(name, parent);
    QFont font("Font", 26);
    text->setFont(font);
    text->moveBy(30,50);

    QGraphicsTextItem* childText;
    QGraphicsRectItem* child;
    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(150,25);
    child->setBrush(brushwhite);

    childText = new QGraphicsTextItem("7", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    values->push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(25,150);
    child->setBrush(brushred);

    childText = new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(150,150);
    child->setBrush(brushblue);

    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    values->push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(25,275);
    child->setBrush(brushyellow);
    values->push_back(childText);

    childText = new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    values->push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(150,275);
    child->setBrush(brushgreen);

    childText = new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    values->push_back(childText);
}
