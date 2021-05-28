// Bernd Uijtdebroeks 2055267
#ifndef TOOLBONUS_H
#define TOOLBONUS_H

#include "civilisation.h"

class ToolBonus : public Civilisation
{
    Q_OBJECT
public:
    ToolBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, int tool);
    ToolBonus(const QJsonObject &json);
    QJsonObject save();

    void giveItems(std::shared_ptr<Player> player); // Gives items on the card to the player

    int getTool() const; // Returns the level of the tool on the card

private:
    int m_tool;
};

#endif // TOOLBONUS_H
