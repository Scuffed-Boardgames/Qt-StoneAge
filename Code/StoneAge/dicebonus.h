#ifndef DICEBONUS_H
#define DICEBONUS_H

#include "civilisation.h"

class DiceBonus : public Civilisation
{
    Q_OBJECT
public:
    DiceBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool card, Resource m_resource);
    DiceBonus(const QJsonObject &json);
    void giveItems(std::shared_ptr<Player> player);
    QJsonObject save();
private:
    Resource m_resource;
};

#endif // DICEBONUS_H
