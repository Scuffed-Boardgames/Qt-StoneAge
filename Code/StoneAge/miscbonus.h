// Bernd Uijtdebroeks 2055267
#ifndef MISCBONUS_H
#define MISCBONUS_H

#include "civilisation.h"

class MiscBonus : public Civilisation
{
    Q_OBJECT
public:
    MiscBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool score, bool food, bool tool);
    MiscBonus(const QJsonObject &json);
    void giveItems(std::shared_ptr<Player> player); // Gives items on the card to the player
    QJsonObject save();

    bool getScore() const;
    bool getFood() const;
    bool getTool() const;

private:
    bool m_score;
    bool m_food;
    bool m_tool;
};

#endif // MISCBONUS_H
