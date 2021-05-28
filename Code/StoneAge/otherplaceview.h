// Denzell Mgbokwere 2054872
#ifndef OTHERPLACEVIEW_H
#define OTHERPLACEVIEW_H

#include <QGraphicsItem>
#include "place.h"

class OtherPlaceView : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    OtherPlaceView(QColor colour, int moveByX, int cost, QString name, std::shared_ptr<Place> place, QGraphicsScene* parentItem);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    std::shared_ptr<Place> getPlace();
    int getCost();

public slots:
    void updateText(); // Updates the boxes and text

private:
    std::shared_ptr<Place> m_place;
    Colour m_owner;
    int m_staticCost;
    QGraphicsRectItem* m_indicator;
};

#endif // OTHERPLACEVIEW_H
