// Denzell Mgbokwere 2054872
#include "resourceplaceview.h"

#include <QGraphicsScene>

ResourcePlaceView::ResourcePlaceView(const QColor colour, const QString name, const int moveByX, std::shared_ptr<Place> place, QGraphicsScene* parentItem)
    : m_place(place){
    parentItem->addItem(this);
    this->moveBy(moveByX, 100);
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsRectItem* parent = new QGraphicsRectItem(0, 0, 300, 350, this);
    parent->setBrush(colour);

    QGraphicsTextItem* text = new QGraphicsTextItem(name, parent);
    QFont font("Font", 26);
    text->setFont(font);
    text->moveBy(0,25);
    if(name == "Hunt"){
        text->moveBy(100,0);
    }else if(name == "Forest"){
        text->moveBy(20,0);
    }else if(name == "Clay Pit"){
        text->moveBy(10,0);
    }else if(name == "Quarry"){
        text->moveBy(20,0);
    }else if(name == "River"){
        text->moveBy(30,0);
    }

    QGraphicsTextItem* childText;
    QGraphicsRectItem* child;
    if(name != "Hunt"){
        child = new QGraphicsRectItem(0, 0,100,100, parent);
        child->moveBy(150,10);
        child->setBrush(QColor(234,222,210));//white
        childText = new QGraphicsTextItem("7", child);
        childText->moveBy(22,0);
        childText->setScale(4);
    }

    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(25,120);
    child->setBrush(QColor(237,28,36));//red
    m_redAmount = new QGraphicsTextItem("0", child);
    m_redAmount->moveBy(22,0);
    m_redAmount->setScale(4);

    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(150,120);
    child->setBrush(QColor(63,72,204));//blue
    m_blueAmount= new QGraphicsTextItem("0", child);
    m_blueAmount->moveBy(22,0);
    m_blueAmount->setScale(4);

    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(25,240);
    child->setBrush(QColor(255,242,0));//yellow
    m_yellowAmount = new QGraphicsTextItem("0", child);
    m_yellowAmount->moveBy(22,0);
    m_yellowAmount->setScale(4);

    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(150,240);
    child->setBrush(QColor(34,177,76)); //green
    m_greenAmount = new QGraphicsTextItem("0", child);
    m_greenAmount->moveBy(22,0);
    m_greenAmount->setScale(4);

}


QRectF ResourcePlaceView::boundingRect() const{
    return QRectF(0, 0, 300, 350 );
}

void ResourcePlaceView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    if (painter || option || widget){
    }

}


std::shared_ptr<Place> ResourcePlaceView::getPlace() const{
    return m_place;
}


void ResourcePlaceView::updateText(){
    int redAmount = m_place->getWorkers(Colour::red);
    m_redAmount->setPlainText(QString::number(redAmount));

    int blueAmount = m_place->getWorkers(Colour::blue);
    m_blueAmount->setPlainText(QString::number(blueAmount));

    int yellowAmount = m_place->getWorkers(Colour::yellow);
    m_yellowAmount->setPlainText(QString::number(yellowAmount));

    int greenAmount = m_place->getWorkers(Colour::green);
    m_greenAmount->setPlainText(QString::number(greenAmount));

}



