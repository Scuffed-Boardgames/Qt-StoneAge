#include "civilisationview.h"
#include <QGraphicsScene>

CivilisationView::CivilisationView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem)
{
    int yPos = 5;
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsRectItem* tile = new QGraphicsRectItem(0, 0, 175, 200, this);
    tile->moveBy(moveByX, 800);
    tile->setBrush(QColor(245, 241, 214));
    parentItem->addItem(this);

    m_holder = new QGraphicsRectItem(0, 0, 40, 40, tile);
    m_holder->moveBy(67.5, yPos);
    QGraphicsRectItem* tleft = new QGraphicsRectItem(0, 0, 20, 20, m_holder);
    tleft->moveBy(0, 0);
    tleft->setBrush(QColor(115,75,0));
    QGraphicsRectItem* tright = new QGraphicsRectItem(0, 0, 20, 20, m_holder);
    tright->moveBy(20, 0);
    tright->setBrush(QColor(220,85,57));
    QGraphicsRectItem* bright = new QGraphicsRectItem(0, 0, 20, 20, m_holder);
    bright->moveBy(0, 20);
    bright->setBrush(QColor(75,75,75));
    QGraphicsRectItem* bleft = new QGraphicsRectItem(0, 0, 20, 20, m_holder);
    bleft->moveBy(20, 20);
    bleft->setBrush(QColor(255,215,0));

    QFont font2("font", 20);
    m_cost = new QGraphicsSimpleTextItem("", m_holder);
    m_cost->setBrush(Qt::white);
    m_cost->setFont(font2);
    m_cost->setScale(1.5);
    m_cost->moveBy(9, -2);
    QPen pen;
    pen.setBrush(Qt::black);
    m_cost->setPen(pen);
    yPos += 40;

    yPos += 5;
    m_indicator = new QGraphicsRectItem(0, 0, 75, 75, tile);
    m_indicator->moveBy(50, yPos);
    m_indicator->setBrush(QColor(234, 222, 210)); //white-ish
    yPos += 75;

    QFont font1("Font", 14);
    yPos += 45;
    m_underCardBonus = new QGraphicsTextItem("", tile);
    m_underCardBonus->setFont(font1);
    m_underCardBonus->moveBy(0, yPos);

    updateBuilding(civilisation);
}


QRectF CivilisationView::boundingRect() const
{
    return QRectF(m_x, 800, 175 , 200);
}

void CivilisationView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (painter || option || widget){
    }

}

void CivilisationView::updateBuilding(std::shared_ptr<Civilisation> civilisation){
    m_civilisation = civilisation;
    m_cost->setText(QString::number(m_civilisation->getCost()));
}