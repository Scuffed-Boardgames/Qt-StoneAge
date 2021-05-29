#include "setbonus.h"
#include "showcivreward.h"

SetBonus::SetBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, int amount, Resource resource)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost), m_amount(amount), m_resource(resource){
}

SetBonus::SetBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt()), m_amount(json["amount"].toInt()), m_resource((Resource)(json["resource"].toInt()))
{}

void SetBonus::giveItems(std::shared_ptr<Player> player){
    ShowCivReward show(player, false, false, false, false, false, (int)m_resource, m_amount);
    show.exec();
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
                        {"bonus", (int)getBonus()},
                        {"cost", getCost()},
                        {"amount", m_amount},
                        {"resource", (int)m_resource},
                        };
    return json;
}

int SetBonus::getAmount() const
{
    return m_amount;
}

Resource SetBonus::getResource() const
{
    return m_resource;
}
