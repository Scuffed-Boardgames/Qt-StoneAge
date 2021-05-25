#include "pickbonusview.h"
#include "pickbonus.h"
#include <QGraphicsScene>
#include "dicebonus.h"
#include "QColor"
#include "QBrush"
#include "QFont"
#include "QPen"

PickBonusView::PickBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem) :
    CivilisationView(moveByX, civilisation, parentItem){

    QGraphicsRectItem* holder1 = new QGraphicsRectItem(0, 0, 30, 30, this);
    holder1->moveBy(95, 135);
    QGraphicsRectItem* tleft1 = new QGraphicsRectItem(0, 0, 15, 15, holder1);
    tleft1->moveBy(0, 0);
    tleft1->setBrush(QColor(115,75,0));
    QGraphicsRectItem* tright1 = new QGraphicsRectItem(0, 0, 15, 15, holder1);
    tright1->moveBy(15, 0);
    tright1->setBrush(QColor(220,85,57));
    QGraphicsRectItem* bright1 = new QGraphicsRectItem(0, 0, 15, 15, holder1);
    bright1->moveBy(0, 15);
    bright1->setBrush(QColor(75,75,75));
    QGraphicsRectItem* bleft1 = new QGraphicsRectItem(0, 0, 15, 15, holder1);
    bleft1->moveBy(15, 15);
    bleft1->setBrush(QColor(255,215,0));

    QGraphicsRectItem* holder2 = new QGraphicsRectItem(0, 0, 30, 30, this);
    holder2->moveBy(50, 135);
    QGraphicsRectItem* tleft2 = new QGraphicsRectItem(0, 0, 15, 15, holder2);
    tleft2->moveBy(0, 0);
    tleft2->setBrush(QColor(115,75,0));
    QGraphicsRectItem* tright2 = new QGraphicsRectItem(0, 0, 15, 15, holder2);
    tright2->moveBy(15, 0);
    tright2->setBrush(QColor(220,85,57));
    QGraphicsRectItem* bright2 = new QGraphicsRectItem(0, 0, 15, 15, holder2);
    bright2->moveBy(0, 15);
    bright2->setBrush(QColor(75,75,75));
    QGraphicsRectItem* bleft2 = new QGraphicsRectItem(0, 0, 15, 15, holder2);
    bleft2->moveBy(15, 15);
    bleft2->setBrush(QColor(255,215,0));


}
