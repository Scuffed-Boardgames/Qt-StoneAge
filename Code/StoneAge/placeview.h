#ifndef PLACEVIEW_H
#define PLACEVIEW_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "colour.h"
#include <QPainter>


class PlaceView : public QGraphicsItem
{

public:
    PlaceView(QColor colour, QString name, int moveByX, QGraphicsScene* parent);
    void addWorkers(int amount, Colour colour);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int m_x;
    QGraphicsTextItem* m_redAmount;
    QGraphicsTextItem* m_blueAmount;
    QGraphicsTextItem* m_greenAmount;
    QGraphicsTextItem* m_yellowAmount;
};

#endif // PLACEVIEW_H
