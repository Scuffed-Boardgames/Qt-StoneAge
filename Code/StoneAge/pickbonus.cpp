#include "pickbonus.h"
#include "pickresources.h"

PickBonus::PickBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost)
{}

PickBonus::PickBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt())
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
                        {"choice", 2}
                        };
    return json;
}
