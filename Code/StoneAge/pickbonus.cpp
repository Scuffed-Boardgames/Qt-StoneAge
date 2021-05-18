#include "pickbonus.h"
#include "pickresources.h"

PickBonus::PickBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, int choice)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost), m_choice(choice)
{}

PickBonus::PickBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt()), m_choice(json["choice"].toInt())
{}

void PickBonus::giveItems(std::shared_ptr<Player> player)
{
    PickResources* pick = new PickResources(player);
    pick->exec();
    giveBonus(player);
}

QJsonObject PickBonus::save()
{
    QJsonObject json = {{"colour", (int)getStandingColour()},
                        {"farmers", getFarmers()},
                        {"makers", getMakers()},
                        {"builders", getBuilders()},
                        {"shamen", getShamen()},
                        {"bonus", (int)getBonus()},
                        {"cost", getCost()},
                        {"choice", m_choice}
                        };
    return json;
}
