#ifndef SETBONUSVIEW_H
#define SETBONUSVIEW_H

#include "civilisationview.h"

class SetBonusView : public CivilisationView
{
public:
    SetBonusView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem);
private:
    QGraphicsRectItem* m_resource;
    QGraphicsSimpleTextItem* m_amount;
};

#endif // SETBONUSVIEW_H
