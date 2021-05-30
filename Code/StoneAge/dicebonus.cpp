// Bernd Uijtdebroeks 2055267
#include "dicebonus.h"
#include "rollresources.h"

DiceBonus::DiceBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, Resource resource)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost), m_resource(resource){
}

DiceBonus::DiceBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt()), m_resource((Resource)(json["diceResource"].toInt()))
{}

void DiceBonus::giveItems(std::shared_ptr<Player> player)
{
    RollResources roll(2, m_resource, player, nullptr);
    roll.exec();
    if (roll.getGain() > 0){
        player->addResource(m_resource, roll.getGain());
    }
    giveBonus(player);
}

QJsonObject DiceBonus::save()
{
    QJsonObject json = {{"colour", (int)getStandingColour()},
                        {"farmers", getFarmers()},
                        {"makers", getMakers()},
                        {"builders", getBuilders()},
                        {"shamen", getShamen()},
                        {"bonus", (int)getBonus()},
                        {"cost", getCost()},
                        {"diceResource", (int)m_resource}
                        };
    return json;
}

Resource DiceBonus::getResource() const
{
    return m_resource;
}
