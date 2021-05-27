// Denzell Mgbokwere 2054872
#ifndef PICKBONUSVIEW_H
#define PICKBONUSVIEW_H

#include "civilisationview.h"

class PickBonusView : public CivilisationView
{
public:
    PickBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem);
};

#endif // PICKBONUSVIEW_H
