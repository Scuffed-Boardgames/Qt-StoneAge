// Bernd Uijtdebroeks 2055267
#include "cardbonus.h"
#include "showcivreward.h"

CardBonus::CardBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost), m_card(nullptr)
{}

CardBonus::CardBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt()), m_card(nullptr)
{}

QJsonObject CardBonus::save()
{
    QJsonObject json = {{"colour", (int)getStandingColour()},
                        {"farmers", getFarmers()},
                        {"makers", getMakers()},
                        {"builders", getBuilders()},
                        {"shamen", getShamen()},
                        {"bonus", (int)getBonus()},
                        {"cost", getCost()},
                        {"hasCard", false}
                        };
    return json;
}

void CardBonus::setCard(std::shared_ptr<Civilisation> card){
    m_card = card;
}

void CardBonus::giveItems(std::shared_ptr<Player> player){
    ShowCivReward show(player, true);
    show.exec();
    m_card->giveBonus(player);
    giveBonus(player);
}
