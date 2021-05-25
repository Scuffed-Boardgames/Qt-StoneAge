#ifndef DICEBONUSVIEW_H
#define DICEBONUSVIEW_H

#include "civilisationview.h"

class DiceBonusView : public CivilisationView
{
public:
    DiceBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem);
};

#endif // DICEBONUSVIEW_H
