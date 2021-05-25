#include "rollbonus.h"

RollBonus::RollBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, int die1, int die2, int die3, int die4)
    : Civilisation(colour, farmers, makers, builders, shamen, bonus, cost)
{
    m_dice[0] = die1;
    m_dice[1] = die2;
    m_dice[2] = die3;
    m_dice[3] = die4;
    if(m_dice[0] + m_dice[1] + m_dice[2] + m_dice[3] == 0){
        rollDice();
    }
}

RollBonus::RollBonus(const QJsonObject &json)
    : Civilisation((Colour)(json["colour"].toInt()), json["farmers"].toInt(), json["makers"].toInt(), json["builders"].toInt(), json["shamen"].toInt(),
      (CivBonus)(json["bonus"].toInt()), json["cost"].toInt())
{
     m_dice[0] = json["die1"].toInt();
     m_dice[1] = json["die2"].toInt();
     m_dice[2] = json["die3"].toInt();
     m_dice[3] = json["die4"].toInt();
}

void RollBonus::giveItems(std::shared_ptr<Player> player)
{
    giveBonus(player);
}

QJsonObject RollBonus::save()
{
    QJsonObject json = {{"colour", (int)getStandingColour()},
                        {"farmers", getFarmers()},
                        {"makers", getMakers()},
                        {"builders", getBuilders()},
                        {"shamen", getShamen()},
                        {"bonus", (int)getBonus()},
                        {"cost", getCost()},
                        {"die1", m_dice[0]},
                        {"die2", m_dice[1]},
                        {"die3", m_dice[2]},
                        {"die4", m_dice[3]}
                        };
    return json;
}

void RollBonus::rollDice()
{
    for(int i = 0; i < 4; ++i){
        m_dice[i] = rand() % 6 + 1;
    }
}

int RollBonus::getDie(int die)
{
    return m_dice[die - 1];
}

