// Denzell Mgbokwere 2054872
#include "rollbonusview.h"

#include<QColor>
#include<QBrush>

RollBonusView::RollBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem) :
    CivilisationView(moveByX, civilisation, parentItem){

    QGraphicsRectItem* holder1 = new QGraphicsRectItem(0, 0, 30, 30, this);
    holder1->moveBy(90, 135);
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

    QGraphicsRectItem* dice = new QGraphicsRectItem(0, 0, 30, 30, this);
    dice->moveBy(50, 135);
    dice->setBrush(Qt::white);
    QGraphicsEllipseItem* dot1 = new QGraphicsEllipseItem(0, 0, 5, 5, dice);
    dot1->moveBy(5, 5);
    dot1->setBrush(Qt::black);
    QGraphicsEllipseItem* dot2 = new QGraphicsEllipseItem(0, 0, 5, 5, dice);
    dot2->moveBy(20, 5);
    dot2->setBrush(Qt::black);
    QGraphicsEllipseItem* dot3 = new QGraphicsEllipseItem(0, 0, 5, 5, dice);
    dot3->moveBy(12.5, 12.5);
    dot3->setBrush(Qt::black);
    QGraphicsEllipseItem* dot4 = new QGraphicsEllipseItem(0, 0, 5, 5, dice);
    dot4->moveBy(5, 20);
    dot4->setBrush(Qt::black);
    QGraphicsEllipseItem* dot5 = new QGraphicsEllipseItem(0, 0, 5, 5, dice);
    dot5->moveBy(20, 20);
    dot5->setBrush(Qt::black);



}
