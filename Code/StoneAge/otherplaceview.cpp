#include "otherplaceview.h"
#include <QBrush>
#include <QFont>
#include <QGraphicsScene>

OtherPlaceView::OtherPlaceView(QColor colour, int moveByX, int textMoveX, int cost, QString name, QGraphicsScene* parentItem)
{
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
      m_x = moveByX;
    QGraphicsRectItem* tile = new QGraphicsRectItem(0, 0,500, 400, this);
    tile->moveBy(moveByX, 500);
    tile->setBrush(colour);
    parentItem->addItem(this);

    QFont font("Font", 26);
    QGraphicsTextItem* text = new QGraphicsTextItem(name, tile);
    text->setFont(font);
    text->moveBy(textMoveX, 50);//210/180

    m_indicator = new QGraphicsRectItem(0, 0,300, 200, tile);
    m_indicator->moveBy(100, 150);
    m_indicator->setBrush(QColor(234, 222, 210)); //white-ish
    m_owner = Colour::none;
    m_staticCost = cost;

}

int OtherPlaceView::getCost()
{
    return m_staticCost;

}


void OtherPlaceView::setColour(Colour colour)
{
    switch (colour) {
    case Colour::red:
        m_indicator->setBrush(QColor(237,28,36));
        return;
    case Colour::blue:
        m_indicator->setBrush(QColor(63,72,204));
        return;
    case Colour::yellow:
        m_indicator->setBrush(QColor(255,242,0));
        return;
    case Colour::green:
        m_indicator->setBrush(QColor(34,177,76));
        return;
    default:
        m_indicator->setBrush(QColor(234, 222, 210));
        return;

    }

}

QRectF OtherPlaceView::boundingRect() const
{
    return QRectF(m_x, 500, 500, 400 );
}

void OtherPlaceView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}
