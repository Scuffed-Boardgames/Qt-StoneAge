#include "miscbonus.h"

MiscBonus::MiscBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool card, bool score, bool food, bool tool)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost, card), m_score(score), m_food(food), m_tool(tool){
}

MiscBonus::MiscBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt(), json["card"].toBool()), m_score(json["score"].toBool()), m_food(json["food"].toBool()), m_tool(json["tool"].toBool())
{}

void MiscBonus::giveItems(std::shared_ptr<Player> player)
{
    if(m_score){
        player->addScore(3);
    }
    if(m_food){
        player->addFoodGain();
    }
    if(m_tool){
        player->addTool();
    }
    giveBonus(player);
}

QJsonObject MiscBonus::save()
{
    QJsonObject json = {{"colour", (int)getStandingColour()},
                        {"farmers", getFarmers()},
                        {"makers", getMakers()},
                        {"builders", getBuilders()},
                        {"shamen", getShamen()},
                        {"makers", (int)getBonus()},
                        {"cost", getCost()},
                        {"card", (int)getCard()},
                        {"score", m_score},
                        {"food", m_food},
                        {"tool", m_tool}
                        };
    return json;
}
