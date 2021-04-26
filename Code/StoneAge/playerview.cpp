#include "playerview.h"
#include <QGraphicsView>
#include <QGraphicsTextItem>
PlayerView::PlayerView(const QColor color, const std::shared_ptr<Player> player, QObject* parent) : QGraphicsScene(parent), m_player(player)
{
    QBrush background;
    background.setColor(color);
    background.setStyle(Qt::SolidPattern);
    setBackgroundBrush(background);
    m_recources.push_back(addText("Food: " + QString::number(m_player->getResource(Resource::food))));
    m_recources.push_back(addText("Wood: " + QString::number(m_player->getResource(Resource::wood))));
    m_recources.push_back(addText("Clay: " + QString::number(m_player->getResource(Resource::clay))));
    m_recources.push_back(addText("Stone: " + QString::number(m_player->getResource(Resource::stone))));
    m_recources.push_back(addText("Gold: " + QString::number(m_player->getResource(Resource::gold))));
    m_recources.push_back(addText("Food made: " + QString::number(m_player->getFoodGain())));
    m_recources.push_back(addText("Amount of workers: "+ QString::number(m_player->getFreeWorkers()) + "/" + QString::number(m_player->getWorkerCount())));
    for (int i = 0; i < (int)m_recources.size(); ++i) {
        m_recources[i]->moveBy(0, 24*i);
        m_recources[i]->setScale(2);
    }
    connect(player.get(), &Player::dataChanged, this, &PlayerView::updateText);
}
void PlayerView::updateText(){
    m_recources[0]->setPlainText("Food: " + QString::number(m_player->getResource(Resource::food)));
    m_recources[1]->setPlainText("Wood: " + QString::number(m_player->getResource(Resource::wood)));
    m_recources[2]->setPlainText("Clay: " + QString::number(m_player->getResource(Resource::clay)));
    m_recources[3]->setPlainText("Stone: " + QString::number(m_player->getResource(Resource::stone)));
    m_recources[4]->setPlainText("Gold: " + QString::number(m_player->getResource(Resource::gold)));
    m_recources[5]->setPlainText("Food made: " + QString::number(m_player->getFoodGain()));
    m_recources[6]->setPlainText("Amount of workers: "+ QString::number(m_player->getFreeWorkers()) + "/" + QString::number(m_player->getWorkerCount()));

}
