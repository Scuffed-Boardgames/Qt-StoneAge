#include "toolbonus.h"

ToolBonus::ToolBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool card, int tool)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost, card), m_tool(tool)
{}

ToolBonus::ToolBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt(), json["card"].toBool()), m_tool(json["tool"].toInt())
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
                        {"card", getCard()},
                        {"tool", m_tool}
                        };
    return json;
}

void ToolBonus::giveItems(std::shared_ptr<Player> player)
{
    player->addExtraTool(m_tool);
}
