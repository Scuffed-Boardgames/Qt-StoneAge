#ifndef RESOURCEPLACEVIEW_H
#define RESOURCEPLACEVIEW_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include "colour.h"
#include "place.h"


class ResourcePlaceView :  public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    ResourcePlaceView(QColor colour, QString name, int moveByX, Place* m_place, QGraphicsScene* parent);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    Place* getPlace() const;

public slots:
    void updateText();

private:
    int m_x;
    QGraphicsTextItem* m_redAmount;
    QGraphicsTextItem* m_blueAmount;
    QGraphicsTextItem* m_greenAmount;
    QGraphicsTextItem* m_yellowAmount;
    Place* m_place;
};

#endif // RESOURCEPLACEVIEW_H
