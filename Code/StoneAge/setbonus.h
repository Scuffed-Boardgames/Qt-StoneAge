// Bernd Uijtdebroeks 2055267
#ifndef SETBONUS_H
#define SETBONUS_H

#include "civilisation.h"

class SetBonus : public Civilisation
{
    Q_OBJECT
public:
    SetBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, int amount, Resource resource);
    SetBonus(const QJsonObject &json);
    void giveItems(std::shared_ptr<Player> player); // Gives items on the card to the player
    QJsonObject save();

    int getAmount() const;
    Resource getResource() const;

private:
    int m_amount;
    Resource m_resource;
};

#endif // SETBONUS_H
