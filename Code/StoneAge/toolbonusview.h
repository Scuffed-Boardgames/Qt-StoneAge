// Denzell Mgbokwere 2054872
#ifndef TOOLBONUSVIEW_H
#define TOOLBONUSVIEW_H

#include "civilisationview.h"

class ToolBonusView : public CivilisationView
{
public:
    ToolBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem);
};

#endif // TOOLBONUSVIEW_H
