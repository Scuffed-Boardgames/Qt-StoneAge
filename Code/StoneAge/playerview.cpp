#include "playerview.h"
#include <QGraphicsView>
#include <QGraphicsTextItem>
PlayerView::PlayerView(const QColor color, const std::shared_ptr<Player> player, QObject* parent) : QGraphicsScene(parent), m_player(player){
    setBackgroundBrush(QBrush(color));

    Tool* tools = m_player->getTools();

    m_recources.push_back(addText("Food: " + QString::number(m_player->getResource(Resource::food))));
    m_recources.push_back(addText("Wood: " + QString::number(m_player->getResource(Resource::wood))));
    m_recources.push_back(addText("Clay: " + QString::number(m_player->getResource(Resource::clay))));
    m_recources.push_back(addText("Stone: " + QString::number(m_player->getResource(Resource::stone))));
    m_recources.push_back(addText("Gold: " + QString::number(m_player->getResource(Resource::gold))));
    m_recources.push_back(addText("Food made: " + QString::number(m_player->getFoodGain())));
    m_recources.push_back(addText("Tools: +" + QString::number(tools[0].getLevel()) + "/+" + QString::number(tools[1].getLevel()) + "/+" + QString::number(tools[2].getLevel())));
    m_recources.push_back(addText("Workers: " + QString::number(m_player->getFreeWorkers()) + "/" + QString::number(m_player->getWorkerCount())));
    m_recources.push_back(addText("Buildings: " + QString::number(m_player->getBuildingCount())));
    m_recources.push_back(addText("Score: "+ QString::number(m_player->getScore())));

    std::vector<int> xtratools = m_player->getExtraTools();
    QString text;
    if(xtratools.size() > 0){
        text += "Extra tools:";
        while(xtratools.size() != 0){
            text += " +" + QString::number( xtratools.back());
            xtratools.pop_back();
            if(xtratools.size() > 0){
                text += "/";
            }
        }
        m_recources.push_back(addText(text));
    }


    for (int i = 0; i < (int)m_recources.size(); ++i) {
        m_recources[i]->moveBy(0, 24*i);
        m_recources[i]->setScale(2);
        m_recources[i]->setDefaultTextColor(Qt::white);
    }
    connect(player.get(), &Player::dataChanged, this, &PlayerView::updateText);
}
void PlayerView::updateText(){
    Tool* tools = m_player->getTools();
    m_recources[0]->setPlainText("Food: " + QString::number(m_player->getResource(Resource::food)));
    m_recources[1]->setPlainText("Wood: " + QString::number(m_player->getResource(Resource::wood)));
    m_recources[2]->setPlainText("Clay: " + QString::number(m_player->getResource(Resource::clay)));
    m_recources[3]->setPlainText("Stone: " + QString::number(m_player->getResource(Resource::stone)));
    m_recources[4]->setPlainText("Gold: " + QString::number(m_player->getResource(Resource::gold)));
    m_recources[5]->setPlainText("Food made: " + QString::number(m_player->getFoodGain()));
    m_recources[6]->setPlainText("Tools: +" + QString::number(tools[0].getLevel()) + "/+" + QString::number(tools[1].getLevel()) + "/+" + QString::number(tools[2].getLevel()));
    m_recources[7]->setPlainText("Workers: "+ QString::number(m_player->getFreeWorkers()) + "/" + QString::number(m_player->getWorkerCount()));
    m_recources[8]->setPlainText("Buildings: "+ QString::number(m_player->getBuildingCount()));

    std::vector<int> xtratools = m_player->getExtraTools();
    QString text;
    if(m_recources.back()->toPlainText()[0] == 'E'){
        removeItem(m_recources.back());
        m_recources.pop_back();
    }
    if(xtratools.size() > 0){
        text += "Extra tools:";
        while(xtratools.size() != 0){
            text += " +" + QString::number( xtratools.back());
            xtratools.pop_back();
            if(xtratools.size() > 0){
                text += "/";
            }
        }
        m_recources.push_back(addText(text));
        m_recources.back()->moveBy(0, 24 * (m_recources.size() - 1));
        m_recources.back()->setScale(2);
        m_recources.back()->setDefaultTextColor(Qt::white);
    }
}
int PlayerView::showScore(){
    for (QGraphicsTextItem* text : m_recources) {
        text->setVisible(false);
    }
    int score = m_player->calcScore();
    m_recources.push_back(addText("Score: " + QString::number(score)));
    m_recources.back()->setScale(2);
    for (QGraphicsTextItem* text : m_recources) {
        text->setDefaultTextColor(Qt::white);
    }
    return score;
}

int PlayerView::showTieBreak(){
    int tieBreak = m_player->calcTieBreak();
    m_recources.push_back(addText("Tie break: " + QString::number(tieBreak)));
    m_recources.back()->moveBy(0, 24);
    m_recources.back()->setScale(2);
    for (QGraphicsTextItem* text : m_recources) {
        text->setDefaultTextColor(Qt::white);
    }
    return tieBreak;
}
void PlayerView::unEnd(){

    while (m_recources.size() > 9){
        removeItem(m_recources.back());
        m_recources.pop_back();
    }
    for (QGraphicsTextItem* text : m_recources) {
        text->setVisible(true);
    }
}

void PlayerView::highlight(){
    if(m_recources[0]->defaultTextColor() == Qt::black)
        return;
    setBackgroundBrush(backgroundBrush().color().lighter(200));
    for (QGraphicsTextItem* text : m_recources) {
        text->setDefaultTextColor(Qt::black);
    }
}


void PlayerView::unHighlight(){
    if(m_recources[0]->defaultTextColor() == Qt::white)
        return;
    setBackgroundBrush(backgroundBrush().color().darker(200));
    for (QGraphicsTextItem* text : m_recources) {
        text->setDefaultTextColor(Qt::white);
    }
}
