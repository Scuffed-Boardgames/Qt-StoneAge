#ifndef RESOURCEPLACEVIEW_H
#define RESOURCEPLACEVIEW_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include "colour.h"
#include "place.h"


class ResourcePlaceView : public QGraphicsItem
{

public:
    ResourcePlaceView(QColor colour, QString name, int moveByX, Place* m_place, QGraphicsScene* parent);
    void addWorkers(int amount, Colour colour);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int m_x;
    QGraphicsTextItem* m_redAmount;
    QGraphicsTextItem* m_blueAmount;
    QGraphicsTextItem* m_greenAmount;
    QGraphicsTextItem* m_yellowAmount;
    Place* m_place;
};

#endif // RESOURCEPLACEVIEW_H
