#ifndef OTHERPLACEVIEW_H
#define OTHERPLACEVIEW_H

#include <QGraphicsItem>
#include "place.h"
#include "colour.h"

class OtherPlaceView : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    OtherPlaceView(QColor colour, int moveByX, int cost, QString name, Place* place, QGraphicsScene* parentItem);
    int getCost();
    void setColour(Colour colour);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Place* getPlace();

public slots:
    void updateText();

private:
    Place* m_place;
    Colour m_owner;
    int m_x;
    int m_staticCost;
    QGraphicsRectItem* m_indicator;
};

#endif // OTHERPLACEVIEW_H
