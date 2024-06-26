// Bernd Uijtdebroeks 2055267
#include "miscbonus.h"
#include "showcivreward.h"

MiscBonus::MiscBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool score, bool food, bool tool)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost), m_score(score), m_food(food), m_tool(tool){
}

MiscBonus::MiscBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt()), m_score(json["score"].toBool()), m_food(json["food"].toBool()), m_tool(json["tool"].toBool())
{}

void MiscBonus::giveItems(std::shared_ptr<Player> player)
{
    if(m_score){
        ShowCivReward show(player, false, false, true);
        show.exec();
        player->addScore(3);
    }
    if(m_food){
        ShowCivReward show(player, false, true);
        show.exec();
        player->addFoodGain();
    }
    if(m_tool){
        ShowCivReward show(player, false, false, false, true);
        show.exec();
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
                        {"bonus", (int)getBonus()},
                        {"cost", getCost()},
                        {"score", m_score},
                        {"food", m_food},
                        {"tool", m_tool}
                        };
    return json;
}

bool MiscBonus::getFood() const
{
    return m_food;
}

bool MiscBonus::getTool() const
{
    return m_tool;
}

bool MiscBonus::getScore() const
{
    return m_score;
}
