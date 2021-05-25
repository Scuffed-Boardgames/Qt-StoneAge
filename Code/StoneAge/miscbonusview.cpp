#include "miscbonusview.h"
#include "miscbonus.h"

#include <QGraphicsScene>
#include "QColor"
#include "QBrush"
#include "QFont"
#include "QPen"

MiscBonusView::MiscBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem) :
    CivilisationView(moveByX, civilisation, parentItem){
    QGraphicsTextItem* bonusText = new QGraphicsTextItem("", this);
    bonusText->setFont(QFont ("Font", 14));

    std::shared_ptr<MiscBonus> rollBonus = std::dynamic_pointer_cast<MiscBonus>(civilisation);
    if(rollBonus->getFood()){
        bonusText->setPlainText("+1 Food made");
    } else if(rollBonus->getScore()){
        bonusText->setPlainText("+3 Score");
    } else if(rollBonus->getTool()){
        bonusText->setPlainText("+1 Tool level");
    }
    bonusText->setPos(80, 140);
    for(int i = 0; i < bonusText->toPlainText().length(); ++i){
        bonusText->moveBy(-4, 0);
    }

}
