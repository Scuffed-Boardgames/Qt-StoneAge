#include "boardview.h"
#include <QColor>

BoardView::BoardView()
{
}

BoardView::BoardView(qreal x, qreal y, qreal width, qreal height, std::shared_ptr<Board> board, QObject *parent) : QGraphicsScene(x, y, width, height, parent)
{
    m_board = board;
    QBrush brushgold;
    brushgold.setColor(QColor(255,215,0));
    brushgold.setStyle(Qt::SolidPattern);
    QBrush brushgrey;
    brushgrey.setColor(QColor(75,75,75));
    brushgrey.setStyle(Qt::SolidPattern);
    QBrush brushred;
    brushred.setColor(QColor(220,85,57));
    brushred.setStyle(Qt::SolidPattern);
    QBrush brushbrown;
    brushbrown.setColor(QColor(115,75,0));
    brushbrown.setStyle(Qt::SolidPattern);
    QBrush brushgreen;
    brushgreen.setColor(QColor(60,125,0));
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
