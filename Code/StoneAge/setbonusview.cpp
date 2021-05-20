#include "setbonusview.h"
#include <QGraphicsScene>
#include "setbonus.h"
#include "QColor"
#include "QBrush"
#include "QFont"
#include "QPen"

SetBonusView::SetBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem) :
    CivilisationView(moveByX, civilisation, parentItem){

    std::shared_ptr<SetBonus> setBonus = std::dynamic_pointer_cast<SetBonus>(civilisation);
    QGraphicsRectItem* resource = new QGraphicsRectItem(0, 0, 35, 35, this);
    resource->moveBy(70, 135);

    QFont font2("font", 20);
    QGraphicsSimpleTextItem* amount = new QGraphicsSimpleTextItem(QString::number(setBonus->getAmount()), resource);
    amount->setBrush(Qt::white);
    amount->setFont(font2);
    amount->setScale(1.5);
    amount->moveBy(8, -4);
    QPen pen;
    pen.setBrush(Qt::black);
    amount->setPen(pen);
    switch (setBonus->getResource()) {
    case(Resource::food):
        resource->setBrush(QColor(60,125,0));
        return;
    case(Resource::clay):
        resource->setBrush(QColor(220,85,57));
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
