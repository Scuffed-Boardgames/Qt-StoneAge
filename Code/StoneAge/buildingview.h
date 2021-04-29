#ifndef BUILDINGVIEW_H
#define BUILDINGVIEW_H

#include <QGraphicsItem>
#include "setbuilding.h"

class BuildingView :public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    BuildingView(int moveByX, Building *building, QGraphicsScene *parentItem);
    void setOwner(Colour colour);
    Building* getBuilding() const;

public slots:
    void updateText();
    void updateBuilding(Building *building);
private:
    int m_x;
    QGraphicsTextItem* m_text;
    Building* m_building;
    QGraphicsRectItem* m_indicator;
    QGraphicsRectItem* m_cost1;
    QGraphicsRectItem* m_cost2;
    QGraphicsRectItem* m_cost3;
};

#endif // BUILDINGVIEW_H
