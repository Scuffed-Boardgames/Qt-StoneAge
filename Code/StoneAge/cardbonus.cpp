#include "cardbonus.h"

CardBonus::CardBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool hasCard)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost), m_hasCard(hasCard), m_card(nullptr)
{}

CardBonus::CardBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt()), m_hasCard(json["hasCard"].toBool()), m_card(nullptr)
{}

QJsonObject CardBonus::save()
{
    QJsonObject json = {{"colour", (int)getStandingColour()},
                        {"farmers", getFarmers()},
                        {"makers", getMakers()},
                        {"builders", getBuilders()},
                        {"shamen", getShamen()},
                        {"bonus", (int)getBonus()},
                        {"cost", getCost()}
                        };
    return json;
}

void CardBonus::setCard(std::shared_ptr<Civilisation> card){
    m_hasCard = true;
    m_card = card;
}

void CardBonus::giveItems(std::shared_ptr<Player> player)
{
    m_card->giveBonus(player);
    giveBonus(player);
}