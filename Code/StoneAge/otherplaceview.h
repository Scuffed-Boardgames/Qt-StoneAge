#ifndef OTHERPLACEVIEW_H
#define OTHERPLACEVIEW_H

#include <QGraphicsItem>
#include "colour.h"

class OtherPlaceView : public QGraphicsItem
{
public:
    OtherPlaceView(QColor colour, int moveByX,int textMoveX, int cost, QString name, QGraphicsScene* parentItem);
    int getCost();
    void setColour(Colour colour);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    Colour m_owner;
    int m_x;
    int m_staticCost;
    QGraphicsRectItem* m_indicator;
};

#endif // OTHERPLACEVIEW_H
