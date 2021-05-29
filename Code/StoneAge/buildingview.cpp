#include "buildingview.h"

#include <QGraphicsScene>

BuildingView::BuildingView(int moveByX, std::shared_ptr<Building> building, int stackSize, QGraphicsScene* parentItem ) : m_building(building){

    int yPos = 0;
    parentItem->addItem(this);
    this->moveBy(moveByX, 800);
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);

    QGraphicsRectItem* tile = new QGraphicsRectItem(0, 0, 175, 200, this);

    tile->setBrush(QColor(245, 241, 214));

    yPos += 5;
    m_text = new QGraphicsTextItem("", tile);
    m_text->setFont(QFont("Arial", 15));
    m_text->moveBy(40, yPos);

    QGraphicsRectItem* stackHolder = new QGraphicsRectItem(0, 0, 30, 30, tile);
    stackHolder->moveBy(140, 5);
    stackHolder->setBrush(Qt::gray);
    m_stackAmount = new QGraphicsTextItem("7", stackHolder);
    m_stackAmount->setFont(QFont("Arial",15));
    m_stackAmount->moveBy(5,0);

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


    m_holder = new QGraphicsRectItem(0, 0, 50, 50, tile);
    m_holder->moveBy(95, yPos);
    QGraphicsRectItem* tleft = new QGraphicsRectItem(0, 0, 25, 25, m_holder);
    tleft->moveBy(0, 0);
    tleft->setBrush(QColor(115,75,0));
    QGraphicsRectItem* tright = new QGraphicsRectItem(0, 0, 25, 25, m_holder);
    tright->moveBy(25, 0);
    tright->setBrush(QColor(220,85,57));
    QGraphicsRectItem* bright = new QGraphicsRectItem(0, 0, 25, 25, m_holder);
    bright->moveBy(0, 25);
    bright->setBrush(QColor(75,75,75));
    QGraphicsRectItem* bleft = new QGraphicsRectItem(0, 0, 25, 25, m_holder);
    bleft->moveBy(25, 25);
    bleft->setBrush(QColor(255,215,0));

    m_diff = new QGraphicsSimpleTextItem("", m_holder);
    m_diff->setBrush(Qt::white);
    m_diff->setFont(QFont("Arial", 26));
    m_diff->setScale(1.5);
    m_diff->moveBy(11, -5);
    m_diff->setPen(QPen(Qt::black));
    m_minMax = new QGraphicsSimpleTextItem("", m_holder);
    m_minMax->moveBy(-60, 0);
    m_minMax->setFont(QFont("Arial", 26));
    m_minMax->setScale(1.5);

    updateBuilding(m_building, stackSize);

}


QRectF BuildingView::boundingRect() const
{
    return QRectF(0, 0, 175 , 200);
}

void BuildingView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (painter || option || widget){
    }

}


std::shared_ptr<Building> BuildingView::getBuilding() const
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

void BuildingView::updateBuilding(std::shared_ptr<Building> building, int stackSize){
    m_stackAmount->setPlainText(QString::number(stackSize));
    m_building = building;
    QString topText = "Score: ";
    std::shared_ptr<SetBuilding> setBuilding = std::dynamic_pointer_cast<SetBuilding>(building);
    std::shared_ptr<VarBuilding> varBuilding = std::dynamic_pointer_cast<VarBuilding>(building);
    QGraphicsRectItem* costs[3] = {m_cost1, m_cost2, m_cost3};
    if(setBuilding){
        int pos = 0;
        topText += QString::number(setBuilding->getScoreGain());
        setOrVar(true);
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
        m_text->setPlainText(topText);
        updateText();
    } else if(varBuilding){
        int min = varBuilding->getTotalMin();
        int max = varBuilding->getTotalMax();
        topText += "?";
        setOrVar(false);
        m_diff->setText(QString::number(varBuilding->getDiff()));
        if(min == max){
            m_minMax->setPos(-60, -2);
            m_minMax->setText(QString::number(max));
        } else{
            m_minMax->setPos(-90, -2);
            m_minMax->setText(QString::number(min) + "-" + QString::number(max));
        }
        m_text->setPlainText(topText);
        updateText();
    } else {
        QGraphicsRectItem* costs[3] = {m_cost1, m_cost2, m_cost3};
        for(int i = 0; i < 3; ++i){
            costs[i]->setVisible(false);
        }
        m_holder->setVisible(false);
        m_minMax->setVisible(false);
        m_indicator->setVisible(false);
        m_text->setVisible(false);
    }
}


void BuildingView::setOrVar(bool isSet){
    m_indicator->setVisible(true);
    QGraphicsRectItem* costs[3] = {m_cost1, m_cost2, m_cost3};
    for(int i = 0; i < 3; ++i){
        costs[i]->setVisible(isSet);
    }
    m_holder->setVisible(!isSet);
    m_minMax->setVisible(!isSet);


}
