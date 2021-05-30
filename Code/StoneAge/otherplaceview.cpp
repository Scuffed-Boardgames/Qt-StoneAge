// Denzell Mgbokwere 2054872
#include "otherplaceview.h"

#include <QGraphicsScene>

OtherPlaceView::OtherPlaceView(QColor colour, int moveByX, int cost, QString name, std::shared_ptr<Place> place, QGraphicsScene* parentItem)
    : m_place(place), m_owner(Colour::none), m_staticCost(cost){
    parentItem->addItem(this);
    this->moveBy(moveByX, 450);
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsRectItem* tile = new QGraphicsRectItem(0, 0,500, 350, this);

    tile->setBrush(colour);
    QFont font("Font", 26);
    QGraphicsTextItem* text = new QGraphicsTextItem(name, tile);
    text->setFont(font);
    if (name == "Tool Shed")
        text->moveBy(180, 25);
    else
        text->moveBy(210, 25);
    m_indicator = new QGraphicsRectItem(0, 0,300, 200, tile);
    m_indicator->moveBy(100, 100);
    m_indicator->setBrush(QColor(234, 222, 210)); //white-ish


}


QRectF OtherPlaceView::boundingRect() const{
    return QRectF(0, 0, 500, 350 );
}

void OtherPlaceView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (painter || option || widget){
    }
}




std::shared_ptr<Place> OtherPlaceView::getPlace(){
    return m_place;
}

int OtherPlaceView::getCost(){
    return m_staticCost;

}

void OtherPlaceView::updateText(){
    if(m_place->getWorkers(Colour::red) != 0){
        m_indicator->setBrush(QColor(237,28,36));
        return;
    }
    else if(m_place->getWorkers(Colour::blue) != 0){
        m_indicator->setBrush(QColor(63,72,204));
        return;
    }
    else if(m_place->getWorkers(Colour::yellow) != 0){
        m_indicator->setBrush(QColor(255,242,0));
        return;
    }
    else if(m_place->getWorkers(Colour::green) != 0){
        m_indicator->setBrush(QColor(34,177,76));
        return;
    }
    m_indicator->setBrush(QColor(234, 222, 210));
    return;
}
