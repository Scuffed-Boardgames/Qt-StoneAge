// Denzell Mgbokwere 2054872
#ifndef RESOURCEPLACEVIEW_H
#define RESOURCEPLACEVIEW_H

#include <QGraphicsItem>
#include "colour.h"
#include "place.h"


class ResourcePlaceView :  public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    ResourcePlaceView(QColor colour, QString name, int moveByX, std::shared_ptr<Place> m_place, QGraphicsScene* parent);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    std::shared_ptr<Place> getPlace() const;

public slots:
    void updateText();

private:
    int m_x;
    QGraphicsTextItem* m_redAmount;
    QGraphicsTextItem* m_blueAmount;
    QGraphicsTextItem* m_greenAmount;
    QGraphicsTextItem* m_yellowAmount;
    std::shared_ptr<Place> m_place;
};

#endif // RESOURCEPLACEVIEW_H
