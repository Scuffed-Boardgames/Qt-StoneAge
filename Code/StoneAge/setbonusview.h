#ifndef SETBONUSVIEW_H
#define SETBONUSVIEW_H

#include "civilisationview.h"

class SetBonusView : public CivilisationView
{
public:
    SetBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem);
};

#endif // SETBONUSVIEW_H
