#include "placeview.h"
#include <QColor>
#include <QFont>
#include <QBrush>



placeView::placeView(QColor colour, QString name, int moveByX, QGraphicsScene* parentItem, QGraphicsRectItem* father)
{
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    int rectWidth = 300;
    m_x = moveByX;
    QGraphicsRectItem* parent = new QGraphicsRectItem(0, 0, rectWidth, 400, this);
    parent->moveBy(moveByX,100);
    parent->setBrush(colour);
    parentItem->addItem(this);

    QGraphicsTextItem* text = new QGraphicsTextItem(name, parent);
    QFont font("Font", 26);
    text->setFont(font);
    text->moveBy(30,50);

    QGraphicsTextItem* childText;
    QGraphicsRectItem* child;

    child = new QGraphicsRectItem(0, 0,100,100, parent);
    child->moveBy(150,25);
    child->setBrush(QColor(234,222,210));//white
    childText = new QGraphicsTextItem("7", child);
    childText->moveBy(22,0);
    childText->setScale(4);

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

void placeView::addWorkers(int amount, Colour colour){
    switch((int)colour){
    case(0):{
        QString redTextAmount = m_redAmount->toPlainText();
        int redAmount = redTextAmount.toInt();
        redAmount += amount;
        m_redAmount->setPlainText(QString::number(redAmount));
    }
    case(1):{
        QString blueTextAmount = m_blueAmount->toPlainText();
        int blueAmount = blueTextAmount.toInt();
        blueAmount += amount;
        m_redAmount->setPlainText(QString::number(blueAmount));
    }
    case(2):{
        QString yellowTextAmount = m_yellowAmount->toPlainText();
        int yellowAmount = yellowTextAmount.toInt();
        yellowAmount += amount;
        m_redAmount->setPlainText(QString::number(yellowAmount));
    }
    case(3):{
        QString greenTextAmount = m_greenAmount->toPlainText();
        int greenAmount = greenTextAmount.toInt();
        greenAmount += amount;
        m_redAmount->setPlainText(QString::number(greenAmount));
    }
    default:
        return;
    }
}

QRectF placeView::boundingRect() const
{
    return QRectF(m_x,100, 300 , 400 );
}

void placeView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

//    QRectF rec = boundingRect();
//    QBrush brush(Qt::blue);
//    painter->fillRect(rec, brush);
//    painter->drawRect(rec);

}

