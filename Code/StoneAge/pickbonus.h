// Bernd Uijtdebroeks 2055267
#ifndef PICKBONUS_H
#define PICKBONUS_H

#include "civilisation.h"

class PickBonus : public Civilisation
{
    Q_OBJECT
public:
    PickBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost);
    PickBonus(const QJsonObject &json);
    void giveItems(std::shared_ptr<Player> player); // Gives items on the card to the player
    QJsonObject save();

};

#endif // PICKBONUS_H
