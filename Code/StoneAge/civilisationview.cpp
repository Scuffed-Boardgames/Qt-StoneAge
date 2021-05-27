#include "civilisationview.h"
#include <QGraphicsScene>

CivilisationView::CivilisationView(int moveByX, std::shared_ptr<Civilisation> civilisation, QGraphicsScene *parentItem)
{
    parentItem->addItem(this);
    int yPos = 5;
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->moveBy(moveByX, 800);
    QGraphicsRectItem* tile = new QGraphicsRectItem(0, 0, 175, 200, this);
    tile->setBrush(QColor(245, 241, 214));


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

    m_cost = new QGraphicsSimpleTextItem("", m_holder);
    m_cost->setBrush(Qt::white);
    m_cost->setFont(QFont("Arial", 20));
    m_cost->setScale(1.5);
    m_cost->moveBy(9, -2);
    m_cost->setPen(QPen(Qt::black));
    yPos += 40;

    yPos += 5;
    m_indicator = new QGraphicsRectItem(0, 0, 75, 75, tile);
    m_indicator->moveBy(50, yPos);
    m_indicator->setBrush(QColor(234, 222, 210)); //white-ish
    yPos += 75;

    yPos += 45;
    m_underCardBonus = new QGraphicsTextItem("", tile);
    m_underCardBonus->setFont(QFont("Arial", 14));
    m_underCardBonus->moveBy(0, yPos);

    updateCivilisation(civilisation);
}


QRectF CivilisationView::boundingRect() const
{
    return QRectF(0, 0, 175 , 200);
}

void CivilisationView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (painter || option || widget){
    }

}

void CivilisationView::updateCivilisation(std::shared_ptr<Civilisation> civilisation){
    m_civilisation = civilisation;
    m_cost->setText(QString::number(m_civilisation->getCost()));
    if((int)m_civilisation->getBonus() != -1){
        m_underCardBonus->setPlainText(bonusToString(m_civilisation->getBonus()));
    } else if(m_civilisation->getBuilders() > 0){
        m_underCardBonus->setPlainText(QString::number(m_civilisation->getBuilders()) + " Hut builder(s)");
    } else if(m_civilisation->getShamen() > 0){
        m_underCardBonus->setPlainText(QString::number(m_civilisation->getShamen()) + " Shaman(s)");
    } else if(m_civilisation->getFarmers() > 0){
        m_underCardBonus->setPlainText(QString::number(m_civilisation->getFarmers()) + " Farmer(s)");
    } else if(m_civilisation->getMakers() > 0){
        m_underCardBonus->setPlainText(QString::number(m_civilisation->getMakers()) + " Tool maker(s)");
    }
    m_underCardBonus->setPos(80, 170);
    for(int i = 0; i < m_underCardBonus->toPlainText().length(); ++i){
        m_underCardBonus->moveBy(-4, 0);
    }
}

void CivilisationView::updateText(){
    if(m_civilisation->getStandingColour() == Colour::red){
        m_indicator->setBrush(QColor(237,28,36));
        return;
    }
    else if(m_civilisation->getStandingColour() == Colour::blue){
        m_indicator->setBrush(QColor(63,72,204));
        return;
    }
    else if(m_civilisation->getStandingColour() == Colour::yellow){
        m_indicator->setBrush(QColor(255,242,0));
        return;
    }
    else if(m_civilisation->getStandingColour() == Colour::green){
        m_indicator->setBrush(QColor(34,177,76));
        return;
    }
    m_indicator->setBrush(QColor(234, 222, 210));
    return;

}

QString CivilisationView::bonusToString(CivBonus bonus)
{
    switch(bonus){
    case(CivBonus::art):
        return "Art";
    case(CivBonus::healing):
        return "Healing";
    case(CivBonus::music):
        return "Music";
    case(CivBonus::pottery):
        return "Pottery";
    case(CivBonus::time):
        return "Time";
    case(CivBonus::transport):
        return "Transport";
    case(CivBonus::weaving):
        return "Weaving";
    case(CivBonus::writing):
        return "Writing";
    default:
        return "";
    }

}

std::shared_ptr<Civilisation> CivilisationView::getCivilisation() const
{
    return m_civilisation;
}
