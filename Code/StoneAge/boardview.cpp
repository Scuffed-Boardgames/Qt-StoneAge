#include "boardview.h"
#include <QColor>
#include <QGraphicsTextItem>

BoardView::BoardView()
{
}

BoardView::BoardView(std::shared_ptr<Board> board) : QGraphicsScene()
{
    m_board = board;
    QBrush brushgold;
    brushgold.setColor(QColor(255,215,0)); //gold
    brushgold.setStyle(Qt::SolidPattern);
    QBrush brushgrey;
    brushgrey.setColor(QColor(75,75,75)); //grey
    brushgrey.setStyle(Qt::SolidPattern);
    QBrush brushbrickred;
    brushbrickred.setColor(QColor(220,85,57)); //brick red
    brushbrickred.setStyle(Qt::SolidPattern);
    QBrush brushbrown;
    brushbrown.setColor(QColor(115,75,0)); //brown
    brushbrown.setStyle(Qt::SolidPattern);
    QBrush brushforestgreen;
    brushforestgreen.setColor(QColor(60,125,0)); //forest green
    brushforestgreen.setStyle(Qt::SolidPattern);
    int moveByX = 50;
    int rectWidth = 300;
    QGraphicsRectItem* hunt = new QGraphicsRectItem(0, 0,rectWidth,400);
    hunt->moveBy(moveByX,100);
    hunt->setBrush(brushforestgreen);
    this->addItem(hunt);
    moveByX += rectWidth;
    QGraphicsRectItem* forest = new QGraphicsRectItem(0, 0,rectWidth,400);
    forest->moveBy(moveByX,100);
    forest->setBrush(brushbrown);
    this->addItem(forest);
    moveByX += rectWidth;
    QGraphicsRectItem* claypit = new QGraphicsRectItem(0, 0,rectWidth,400);
    claypit->moveBy(moveByX,100);
    claypit->setBrush(brushbrickred);
    this->addItem(claypit);
    moveByX += rectWidth;
    QGraphicsRectItem* quarry = new QGraphicsRectItem(0, 0,rectWidth,400);
    quarry->moveBy(moveByX,100);
    quarry->setBrush(brushgrey);
    this->addItem(quarry);
    moveByX += rectWidth;
    QGraphicsRectItem* river = new QGraphicsRectItem(0, 0,rectWidth,400);
    river->moveBy(moveByX,100);
    river->setBrush(brushgold);
    this->addItem(river);

    QBrush brushwhite;
    brushwhite.setColor(QColor(234,222,210)); //white
    brushwhite.setStyle(Qt::SolidPattern);
    QBrush brushred;
    brushred.setColor(QColor(237,28,36)); //red
    brushred.setStyle(Qt::SolidPattern);
    QBrush brushblue;
    brushblue.setColor(QColor(63,72,204)); //blue
    brushblue.setStyle(Qt::SolidPattern);
    QBrush brushyellow;
    brushyellow.setColor(QColor(255,242,0)); //yellow
    brushyellow.setStyle(Qt::SolidPattern);
    QBrush brushgreen;
    brushgreen.setColor(QColor(34,177,76)); //green
    brushgreen.setStyle(Qt::SolidPattern);


    QGraphicsTextItem* text = new QGraphicsTextItem("Food", hunt);
    QFont font("Font", 26);
    text->setFont(font);
    text->moveBy(30,50);
    text = new QGraphicsTextItem("Wood", forest);
    text->setFont(font);
    text->moveBy(30,50);
    text = new QGraphicsTextItem("Clay", claypit);
    text->setFont(font);
    text->moveBy(30,50);
    text = new QGraphicsTextItem("Stone", quarry);
    text->setFont(font);
    text->moveBy(30,50);
    text = new QGraphicsTextItem("Gold", river);
    text->setFont(font);
    text->moveBy(30,50);

    QGraphicsTextItem* childText;
    QGraphicsRectItem* child;
    child = new QGraphicsRectItem(0, 0,100,100, hunt);
    child->moveBy(150,25);
    child->setBrush(brushwhite);
    childText = new QGraphicsTextItem("7", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_huntValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, hunt);
    child->moveBy(25,150);
    child->setBrush(brushred);
    childText = new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_huntValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, hunt);
    child->moveBy(150,150);
    child->setBrush(brushblue);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_huntValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, hunt);
    child->moveBy(25,275);
    child->setBrush(brushyellow);
    childText = new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_huntValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, hunt);
    child->moveBy(150,275);
    child->setBrush(brushgreen);
    childText = new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_huntValues.push_back(childText);

    child = new QGraphicsRectItem(0, 0,100,100, forest);
    child->moveBy(150,25);
    child->setBrush(brushwhite);
    childText= new QGraphicsTextItem("7", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_forestValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, forest);
    child->moveBy(25,150);
    child->setBrush(brushred);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_forestValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, forest);
    child->moveBy(150,150);
    child->setBrush(brushblue);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_forestValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, forest);
    child->moveBy(25,275);
    child->setBrush(brushyellow);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_forestValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, forest);
    child->moveBy(150,275);
    child->setBrush(brushgreen);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_forestValues.push_back(childText);

    child = new QGraphicsRectItem(0, 0,100,100, claypit);
    child->moveBy(150,25);
    child->setBrush(brushwhite);
    childText= new QGraphicsTextItem("7", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_claypitValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, claypit);
    child->moveBy(25,150);
    child->setBrush(brushred);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_claypitValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, claypit);
    child->moveBy(150,150);
    child->setBrush(brushblue);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_claypitValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, claypit);
    child->moveBy(25,275);
    child->setBrush(brushyellow);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_claypitValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, claypit);
    child->moveBy(150,275);
    child->setBrush(brushgreen);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_claypitValues.push_back(childText);

    child = new QGraphicsRectItem(0, 0,100,100, quarry);
    child->moveBy(150,25);
    child->setBrush(brushwhite);
    childText= new QGraphicsTextItem("7", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_quarryValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, quarry);
    child->moveBy(25,150);
    child->setBrush(brushred);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_quarryValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, quarry);
    child->moveBy(150,150);
    child->setBrush(brushblue);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_quarryValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, quarry);
    child->moveBy(25,275);
    child->setBrush(brushyellow);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_quarryValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, quarry);
    child->moveBy(150,275);
    child->setBrush(brushgreen);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_quarryValues.push_back(childText);


    child = new QGraphicsRectItem(0, 0,100,100, river);
    child->moveBy(150,25);
    child->setBrush(brushwhite);
    childText= new QGraphicsTextItem("7", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_riverValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, river);
    child->moveBy(25,150);
    child->setBrush(brushred);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_riverValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, river);
    child->moveBy(150,150);
    child->setBrush(brushblue);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_riverValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, river);
    child->moveBy(25,275);
    child->setBrush(brushyellow);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_riverValues.push_back(childText);
    child = new QGraphicsRectItem(0, 0,100,100, river);
    child->moveBy(150,275);
    child->setBrush(brushgreen);
    childText= new QGraphicsTextItem("0", child);
    childText->moveBy(22,0);
    childText->setScale(4);
    m_riverValues.push_back(childText);


    QBrush brushwheatyellow;
    brushwheatyellow.setColor(QColor(245,222,179)); //wheat yellow
    brushwheatyellow.setStyle(Qt::SolidPattern);

    QGraphicsRectItem* field = new QGraphicsRectItem(0, 0,500,400);
    field->moveBy(50,500);
    field->setBrush(brushwheatyellow);
    this->addItem(field);

    QBrush brushpink;
    brushpink.setColor(QColor(254,184,198)); //love pink
    brushpink.setStyle(Qt::SolidPattern);

    QGraphicsRectItem* hut = new QGraphicsRectItem(0, 0,500,400);
    hut->moveBy(550,500);
    hut->setBrush(brushpink);
    this->addItem(hut);

    QBrush brushtoolbrown;
    brushtoolbrown.setColor(QColor(161,133,105)); //tool brown
    brushtoolbrown.setStyle(Qt::SolidPattern);

    QGraphicsRectItem* toolshed = new QGraphicsRectItem(0, 0,500,400);
    toolshed->moveBy(1050,500);
    toolshed->setBrush(brushtoolbrown);
    this->addItem(toolshed);
}
