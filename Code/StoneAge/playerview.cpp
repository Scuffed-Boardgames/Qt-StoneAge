#include "playerview.h"
#include <QGraphicsTextItem>
PlayerView::PlayerView(QColor color, std::shared_ptr<Player> player) : QGraphicsScene(), m_player(player)
{
    QBrush background;
    background.setColor(color);
    background.setStyle(Qt::SolidPattern);
    setBackgroundBrush(background);
    recources.push_back(addText("Food: " + QString::number(m_player->getRecourse(Recourse::food))));
    recources.push_back(addText("Wood: " + QString::number(m_player->getRecourse(Recourse::wood))));
    recources.push_back(addText("Clay: " + QString::number(m_player->getRecourse(Recourse::clay))));
    recources.push_back(addText("Stone: " + QString::number(m_player->getRecourse(Recourse::stone))));
    recources.push_back(addText("Gold: " + QString::number(m_player->getRecourse(Recourse::gold))));
    recources.push_back(addText("Food made: " + QString::number(m_player->getFoodGain())));
    recources.push_back(addText("Amount of workers: " + QString::number(m_player->getWorkerCount())));
    for (int i = 1; i < (int)recources.size(); ++i) {
        recources[i]->moveBy(0, 12*i);

    }
}
