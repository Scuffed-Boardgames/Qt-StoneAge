#ifndef PICKBONUS_H
#define PICKBONUS_H

#include "civilisation.h"

class PickBonus : public Civilisation
{
    Q_OBJECT
public:
    PickBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, int choice);
    PickBonus(const QJsonObject &json);
    void giveItems(std::shared_ptr<Player> player);
    QJsonObject save();
private:
    int m_choice;
};

#endif // PICKBONUS_H
