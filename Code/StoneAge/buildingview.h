#ifndef BUILDINGVIEW_H
#define BUILDINGVIEW_H

#include <QGraphicsItem>
#include "setbuilding.h"
#include "varbuilding.h"

class BuildingView :public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    BuildingView(int moveByX, std::shared_ptr<Building> building, int stackSize, QGraphicsScene *parentItem);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    std::shared_ptr<Building> getBuilding() const;

public slots:
    void updateText();
    void updateBuilding(std::shared_ptr<Building> building, int stackSize);

private:
    void setOrVar(bool isSet);
    int m_x;
    QGraphicsTextItem* m_stackAmount;
    QGraphicsTextItem* m_text;
    std::shared_ptr<Building> m_building;
    QGraphicsRectItem* m_indicator;

    QGraphicsRectItem* m_cost1;
    QGraphicsRectItem* m_cost2;
    QGraphicsRectItem* m_cost3;

    QGraphicsRectItem* m_holder;
    QGraphicsSimpleTextItem* m_diff;
    QGraphicsSimpleTextItem* m_minMax;
};

#endif // BUILDINGVIEW_H
