#include "buildingview.h"
#include <QGraphicsScene>
//#include <QGraphicsTextItem>

BuildingView::BuildingView(int moveByX, Building* building, QGraphicsScene* parentItem ) : m_x(moveByX), m_building(building)
{
    int yPos = 0;
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsRectItem* tile = new QGraphicsRectItem(0, 0, 175, 200, this);
    tile->moveBy(moveByX, 800);
    tile->setBrush(QColor(245, 241, 214));
    parentItem->addItem(this);

    QFont font("Font", 15);
    SetBuilding* setBuilding = dynamic_cast<SetBuilding*>(building);

    QString topText = "Score: ";
    if(setBuilding){
        topText += QString::number(setBuilding->getScoreGain());
    } else{
        topText += "?";
    }
    yPos += 5;
    m_text = new QGraphicsTextItem(topText, tile);
    m_text->setFont(font);
    m_text->moveBy(40, yPos);

    yPos += 40;
    m_indicator = new QGraphicsRectItem(0, 0, 75, 75, tile);
    m_indicator->moveBy(50, yPos);
    m_indicator->setBrush(QColor(234, 222, 210)); //white-ish
    yPos += 75;

    yPos += 15;
    double xPos = 7.5;
    m_cost1 = new QGraphicsRectItem(0, 0, 50, 50, tile);
    m_cost1->moveBy(xPos, yPos);
    xPos += 50 + 5;
    m_cost2 = new QGraphicsRectItem(0, 0, 50, 50, tile);
    m_cost2->moveBy(xPos, yPos);
    xPos += 50 + 5;
    m_cost3 = new QGraphicsRectItem(0, 0, 50, 50, tile);
    m_cost3->moveBy(xPos, yPos);

    if(setBuilding){
        int pos = 0;
        QGraphicsRectItem* costs[3] = {m_cost1, m_cost2, m_cost3};

        for(int i = 0; i < setBuilding->getCost(Resource::wood); ++i){
            costs[pos]->setBrush(QColor(115,75,0));
            ++pos;
        }
        for(int i = 0; i < setBuilding->getCost(Resource::clay); ++i){
            costs[pos]->setBrush(QColor(220,85,57));
            ++pos;
        }
        for(int i = 0; i < setBuilding->getCost(Resource::stone); ++i){
            costs[pos]->setBrush(QColor(75,75,75));
            ++pos;
        }
        for(int i = 0; i < setBuilding->getCost(Resource::gold); ++i){
            costs[pos]->setBrush(QColor(255,215,0));
            ++pos;
        }
    } else{
        m_cost1->setVisible(false);
        m_cost2->setVisible(false);
        m_cost3->setVisible(false);
        QGraphicsRectItem* big = new QGraphicsRectItem(0, 0, 50, 50, tile);
        big->moveBy(90, yPos);
        QGraphicsRectItem* tleft = new QGraphicsRectItem(0, 0, 25, 25, big);
        tleft->moveBy(0, 0);
        tleft->setBrush(QColor(115,75,0));
        QGraphicsRectItem* tright = new QGraphicsRectItem(0, 0, 25, 25, big);
        tright->moveBy(25, 0);
        tright->setBrush(QColor(220,85,57));
        QGraphicsRectItem* bright = new QGraphicsRectItem(0, 0, 25, 25, big);
        bright->moveBy(0, 25);
        bright->setBrush(QColor(75,75,75));
        QGraphicsRectItem* bleft = new QGraphicsRectItem(0, 0, 25, 25, big);
        bleft->moveBy(25, 25);
        bleft->setBrush(QColor(255,215,0));
        QFont font2("font", 26);
        QGraphicsSimpleTextItem* num = new QGraphicsSimpleTextItem("4", big);
        num->setBrush(Qt::white);
        num->setFont(font2);
        num->setScale(1.5);
        num->moveBy(10, -5);
        QPen pen;
        pen.setBrush(Qt::black);
        num->setPen(pen);


    }

}

QRectF BuildingView::boundingRect() const
{
    return QRectF(m_x, 800, 175 , 200);
}

void BuildingView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (painter || option || widget){
    }

}


Building* BuildingView::getBuilding() const
{
    return m_building;
}

void BuildingView::updateText(){
    if(m_building->getStandingColour() == Colour::red){
        m_indicator->setBrush(QColor(237,28,36));
        return;
    }
    else if(m_building->getStandingColour() == Colour::blue){
    m_indicator->setBrush(QColor(63,72,204));
    return;
    }
    else if(m_building->getStandingColour() == Colour::yellow){
    m_indicator->setBrush(QColor(255,242,0));
    return;
    }
    else if(m_building->getStandingColour() == Colour::green){
    m_indicator->setBrush(QColor(34,177,76));
    return;
    }
    m_indicator->setBrush(QColor(234, 222, 210));
    return;

}

void BuildingView::updateBuilding(Building* building){
    m_building = building;
    SetBuilding* setBuilding = dynamic_cast<SetBuilding*>(building);

    if(setBuilding){
        m_cost1->setVisible(true);
        m_cost2->setVisible(true);
        m_cost3->setVisible(true);
        int pos = 0;
        QGraphicsRectItem* costs[3] = {m_cost1, m_cost2, m_cost3};

        for(int i = 0; i < setBuilding->getCost(Resource::wood); ++i){
            costs[pos]->setBrush(QColor(115,75,0));
            ++pos;
        }
        for(int i = 0; i < setBuilding->getCost(Resource::clay); ++i){
            costs[pos]->setBrush(QColor(220,85,57));
            ++pos;
        }
        for(int i = 0; i < setBuilding->getCost(Resource::stone); ++i){
            costs[pos]->setBrush(QColor(75,75,75));
            ++pos;
        }
        for(int i = 0; i < setBuilding->getCost(Resource::gold); ++i){
            costs[pos]->setBrush(QColor(255,215,0));
            ++pos;
        }

    } else{
        m_cost1->setVisible(false);
        m_cost2->setVisible(false);
        m_cost3->setVisible(false);
    }

    QString topText = "Score: ";
    if(setBuilding){
        topText += QString::number(setBuilding->getScoreGain());
    } else{
        topText += "?";
    }
    m_text->setPlainText(topText);
    updateText();
}
