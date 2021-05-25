#ifndef ROLLBONUS_H
#define ROLLBONUS_H

#include "civilisation.h"

class RollBonus : public Civilisation
{
    Q_OBJECT
public:
    RollBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, int die1, int die2, int die3, int die4);
    RollBonus(const QJsonObject &json);
    void giveItems(std::shared_ptr<Player> player);
    QJsonObject save();
private:
    void rollDice();
    int getDie(int number);
    int m_dice[4];
};

#endif // ROLLBONUS_H
