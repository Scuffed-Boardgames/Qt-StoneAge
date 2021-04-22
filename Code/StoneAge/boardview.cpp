#include "boardview.h"
#include <QColor>
#include <QTextItem>

BoardView::BoardView()
{
}

BoardView::BoardView(std::shared_ptr<Board> board) : QGraphicsScene()
{
    m_board = board;
    QBrush brushgold;
    brushgold.setColor(QColor(255,215,0)); //gold
    brushgold.setStyle(Qt::SolidPattern);
    QBrush brushgrey;
    brushgrey.setColor(QColor(75,75,75)); //grey
    brushgrey.setStyle(Qt::SolidPattern);
    QBrush brushred;
    brushred.setColor(QColor(220,85,57)); //brick red
    brushred.setStyle(Qt::SolidPattern);
    QBrush brushbrown;
    brushbrown.setColor(QColor(115,75,0)); //brown
    brushbrown.setStyle(Qt::SolidPattern);
    QBrush brushgreen;
    brushgreen.setColor(QColor(60,125,0)); //forest green
    brushgreen.setStyle(Qt::SolidPattern);
    QGraphicsRectItem* rect;
    int moveByX = 50;
    int rectWidth = 275;
    rect = new QGraphicsRectItem(0, 0,rectWidth,400);
    rect->moveBy(moveByX,100);
    rect->setBrush(brushgreen);
    this->addItem(rect);
    moveByX += 275;
    rect = new QGraphicsRectItem(0, 0,rectWidth,400);
    rect->moveBy(moveByX,100);
    rect->setBrush(brushbrown);
    this->addItem(rect);
    moveByX += 275;
    rect = new QGraphicsRectItem(0, 0,rectWidth,400);
    rect->moveBy(moveByX,100);
    rect->setBrush(brushred);
    this->addItem(rect);
    moveByX += 275;
    rect = new QGraphicsRectItem(0, 0,rectWidth,400);
    rect->moveBy(moveByX,100);
    rect->setBrush(brushgrey);
    this->addItem(rect);
    moveByX += 275;
    rect = new QGraphicsRectItem(0, 0,rectWidth,400);
    rect->moveBy(moveByX,100);
    rect->setBrush(brushgold);
    this->addItem(rect);

}
