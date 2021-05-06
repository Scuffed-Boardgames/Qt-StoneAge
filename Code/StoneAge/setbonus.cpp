#include "setbonus.h"

SetBonus::SetBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool card, int amount, Resource resource)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost, card), m_amount(amount), m_resource(resource){
}

SetBonus::SetBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt(), json["card"].toBool()), m_amount(json["amount"].toInt()), m_resource((Resource)(json["resource"].toInt()))
{}

void SetBonus::giveItems(std::shared_ptr<Player> player)
{
    player->addResource(m_resource, m_amount);
    giveBonus(player);
}

QJsonObject SetBonus::save()
{
    QJsonObject json = {{"colour", (int)getStandingColour()},
                        {"farmers", getFarmers()},
                        {"makers", getMakers()},
                        {"builders", getBuilders()},
                        {"shamen", getShamen()},
                        {"makers", (int)getBonus()},
                        {"cost", getCost()},
                        {"card", getCard()},
                        {"amount", m_amount},
                        {"resource", (int)m_resource},
                        };
    return json;
}
