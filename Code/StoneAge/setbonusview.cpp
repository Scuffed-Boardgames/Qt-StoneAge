#include "setbonusview.h"
#include "setbonus.h"
#include "QColor"
#include "QBrush"

SetBonusView::SetBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem) :
    CivilisationView(moveByX, civilisation,parentItem){
    std::shared_ptr<SetBonus> setbonus = std::dynamic_pointer_cast<SetBonus>(civilisation);
    QGraphicsRectItem* indicator = new QGraphicsRectItem(0, 0, 30, 30, this);
    indicator->moveBy(57.5, 130);
    switch (setBonus->) {

    }
    indicator->setBrush(QColor(234, 222, 210)); //white-ish
}
