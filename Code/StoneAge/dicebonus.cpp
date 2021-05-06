#include "dicebonus.h"
#include "rollresources.h"

DiceBonus::DiceBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool card, Resource resource)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost, card), m_resource(resource){
}

DiceBonus::DiceBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt(), json["card"].toBool()), m_resource((Resource)(json["resource"].toInt()))
{}

void DiceBonus::giveItems(std::shared_ptr<Player> player)
{
    RollResources* roll = new RollResources(2, m_resource, player, nullptr);
    roll->exec();
    if (roll->getGain() > 0){
        player->addResource(m_resource, roll->getGain());
    }
    giveBonus(player);
}
