#ifndef MISCBONUSVIEW_H
#define MISCBONUSVIEW_H

#include "civilisationview.h"

class MiscBonusView : public CivilisationView
{
public:
    MiscBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem);
};

#endif // MISCBONUSVIEW_H
