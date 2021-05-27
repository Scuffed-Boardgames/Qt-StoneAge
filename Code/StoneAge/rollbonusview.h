// Denzell Mgbokwere 2054872
#ifndef ROLLBONUSVIEW_H
#define ROLLBONUSVIEW_H

#include "civilisationview.h"

class RollBonusView : public CivilisationView
{
public:
    RollBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem);
};

#endif // ROLLBONUSVIEW_H
