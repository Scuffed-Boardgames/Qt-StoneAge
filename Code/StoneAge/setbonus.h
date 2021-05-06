#ifndef SETBONUS_H
#define SETBONUS_H

#include "civilisation.h"

class SetBonus : public Civilisation
{
    Q_OBJECT
public:
    SetBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool card, int amount, Resource resource);
    SetBonus(const QJsonObject &json);
    void giveItems(std::shared_ptr<Player> player);
    QJsonObject save();
private:
    int m_amount;
    Resource m_resource;
};

#endif // SETBONUS_H
