// Denzell Mgbokwere 2054872
#include "toolbonusview.h"
#include "toolbonus.h"

#include <QFont>

ToolBonusView::ToolBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem) :
    CivilisationView(moveByX, civilisation, parentItem){
    std::shared_ptr<ToolBonus> toolBonus = std::dynamic_pointer_cast<ToolBonus>(civilisation);
    QGraphicsTextItem* bonusText = new QGraphicsTextItem("+lvl " + QString::number(toolBonus->getTool()) + "Temporary tool", this);
    bonusText->setFont(QFont ("Font", 14));
    bonusText->setPos(80, 140);
    for(int i = 0; i < bonusText->toPlainText().length(); ++i){
        bonusText->moveBy(-4, 0);
    }

}
