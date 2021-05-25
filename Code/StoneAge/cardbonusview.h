#ifndef CARDBONUSVIEW_H
#define CARDBONUSVIEW_H

#include "civilisationview.h"

class CardBonusView : public CivilisationView
{
public:
    CardBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem);
};

#endif // CARDBONUSVIEW_H
