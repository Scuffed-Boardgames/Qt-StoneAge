#include "resourceplaceview.h"
#include <QColor>
#include <QFont>
#include <QBrush>


ResourcePlaceView::ResourcePlaceView(const QColor colour, const QString name, const int moveByX, Place* place, QGraphicsScene* parentItem)
{
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    int rectWidth = 300;
    m_x = moveByX;
    m_place = place;
    QGraphicsRectItem* parent = new QGraphicsRectItem(0, 0, rectWidth, 400, this);
    parent->moveBy(moveByX,100);
    parent->setBrush(colour);
    parentItem->addItem(this);

    QGraphicsTextItem* text = new QGraphicsTextItem(name, parent);
    QFont font("Font", 26);
    text->setFont(font);
    text->moveBy(30,50);
    if(name == "Food"){
        text->moveBy(70,0);
    }

    QGraphicsTextItem* childText;
    QGraphicsRectItem* child;
    if(name != "Food"){
        child = new QGraphicsRectItem(0, 0,100,100, parent);
        child->moveBy(150,25);
        child->setBrush(QColor(234,222,210));//white
        childText = new QGraphicsTextItem("7", child);
        childText->moveBy(22,0);
        childText->setScale(4);
    }

    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(25,150);
    child->setBrush(QColor(237,28,36));//red
    m_redAmount = new QGraphicsTextItem("0", child);
    m_redAmount->moveBy(22,0);
    m_redAmount->setScale(4);

    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(150,150);
    child->setBrush(QColor(63,72,204));//blue
    m_blueAmount= new QGraphicsTextItem("0", child);
    m_blueAmount->moveBy(22,0);
    m_blueAmount->setScale(4);

    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(25,275);
    child->setBrush(QColor(255,242,0));//yellow
    m_yellowAmount = new QGraphicsTextItem("0", child);
    m_yellowAmount->moveBy(22,0);
    m_yellowAmount->setScale(4);

    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(150,275);
    child->setBrush(QColor(34,177,76)); //green
    m_greenAmount = new QGraphicsTextItem("0", child);
    m_greenAmount->moveBy(22,0);
    m_greenAmount->setScale(4);

}

void ResourcePlaceView::updateText()
{

    QString redTextAmount = m_redAmount->toPlainText();
    int redAmount = redTextAmount.toInt();
    redAmount = m_place->getWorkers(Colour::red);
    m_redAmount->setPlainText(QString::number(redAmount));

    QString blueTextAmount = m_blueAmount->toPlainText();
    int blueAmount = blueTextAmount.toInt();
    blueAmount = m_place->getWorkers(Colour::blue);
    m_redAmount->setPlainText(QString::number(blueAmount));

    QString yellowTextAmount = m_yellowAmount->toPlainText();
    int yellowAmount = yellowTextAmount.toInt();
    yellowAmount = m_place->getWorkers(Colour::yellow);
    m_redAmount->setPlainText(QString::number(yellowAmount));


    QString greenTextAmount = m_greenAmount->toPlainText();
    int greenAmount = greenTextAmount.toInt();
    greenAmount = m_place->getWorkers(Colour::green);
    m_redAmount->setPlainText(QString::number(greenAmount));

}

QRectF ResourcePlaceView::boundingRect() const
{
    return QRectF(m_x,100, 300 , 400 );
}

void ResourcePlaceView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (painter || option || widget){
    }

}

Place *ResourcePlaceView::getPlace() const
{
    return m_place;
}

