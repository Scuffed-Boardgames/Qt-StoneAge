#include "cardbonusview.h"

#include <QGraphicsScene>
#include "dicebonus.h"
#include "QColor"
#include "QBrush"
#include "QFont"
#include "QPen"

CardBonusView::CardBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem) :
    CivilisationView(moveByX, civilisation, parentItem){
      QGraphicsRectItem* card = new QGraphicsRectItem(0, 0, 30, 40, this);
      card->moveBy(72.5, 132.5);
      QGraphicsTextItem* cardText = new QGraphicsTextItem("CARD", card);
      cardText->setRotation(90);
      cardText->moveBy(27.5, 0);
}
