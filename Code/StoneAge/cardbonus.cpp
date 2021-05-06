#include "cardbonus.h"

CardBonus::CardBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool card)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost, card), m_card(nullptr)
{}

CardBonus::CardBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt(), json["card"].toBool()), m_card(nullptr)
{}

void CardBonus::setCard(std::shared_ptr<Civilisation> card){
    m_card = card;
}

QJsonObject CardBonus::save()
{
    QJsonObject json = {{"colour", (int)getStandingColour()},
                        {"farmers", getFarmers()},
                        {"makers", getMakers()},
                        {"builders", getBuilders()},
                        {"shamen", getShamen()},
                        {"makers", (int)getBonus()},
                        {"cost", getCost()},
                        {"card", (int)getCard()}
                        };
    return json;
}

void CardBonus::giveItems(std::shared_ptr<Player> player)
{
    m_card->giveBonus(player);
    giveBonus(player);
}
