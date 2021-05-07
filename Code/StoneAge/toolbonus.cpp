#include "toolbonus.h"

ToolBonus::ToolBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, int tool)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost), m_tool(tool)
{}

ToolBonus::ToolBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt()), m_tool(json["tool"].toInt())
{}

QJsonObject ToolBonus::save()
{
    QJsonObject json = {{"colour", (int)getStandingColour()},
                        {"farmers", getFarmers()},
                        {"makers", getMakers()},
                        {"builders", getBuilders()},
                        {"shamen", getShamen()},
                        {"makers", (int)getBonus()},
                        {"cost", getCost()},
                        {"tool", m_tool}
                        };
    return json;
}

void ToolBonus::giveItems(std::shared_ptr<Player> player)
{
    player->addExtraTool(m_tool);
    giveBonus(player);
}
