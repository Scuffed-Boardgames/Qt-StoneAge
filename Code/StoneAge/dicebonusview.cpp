#include "dicebonusview.h"
#include "dicebonus.h"


#include <QColor>
#include <QBrush>


DiceBonusView::DiceBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem) :
    CivilisationView(moveByX, civilisation, parentItem){

    std::shared_ptr<DiceBonus> rollBonus = std::dynamic_pointer_cast<DiceBonus>(civilisation);
    QGraphicsRectItem* resource = new QGraphicsRectItem(0, 0, 30, 30, this);
    resource->moveBy(95, 135);
    QGraphicsRectItem* dice = new QGraphicsRectItem(0, 0, 30, 30, this);
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

    dice->moveBy(50, 135);
    switch (rollBonus->getResource()) {
    case(Resource::wood):
        resource->setBrush(QColor(115,75,0));
        return;
    case(Resource::stone):
        resource->setBrush(QColor(75,75,75));
        return;
    case(Resource::gold):
        resource->setBrush(QColor(255,215,0));
        return;
    default:
        return;
    }
}

