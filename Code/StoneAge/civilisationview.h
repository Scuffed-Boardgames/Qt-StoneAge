#ifndef CIVILISATIONVIEW_H
#define CIVILISATIONVIEW_H
#include "colour.h"
#include "civilisation.h"
#include <QGraphicsItem>
#include <QObject>

class CivilisationView :public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit CivilisationView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    std::shared_ptr<Civilisation> getCivilisation() const;

public slots:
    void updateText();

private:
    QString bonusToString(CivBonus bonus);
    void updateCivilisation(std::shared_ptr<Civilisation> civilisation);

    QGraphicsTextItem* m_underCardBonus;
    std::shared_ptr<Civilisation> m_civilisation;
    QGraphicsSimpleTextItem* m_cost;
    QGraphicsRectItem* m_indicator;
    QGraphicsRectItem* m_holder;

signals:

};

#endif // CIVILISATIONVIEW_H
