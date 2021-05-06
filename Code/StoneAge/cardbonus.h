#ifndef CARDBONUS_H
#define CARDBONUS_H

#include "civilisation.h"

class CardBonus : public Civilisation
{
    Q_OBJECT
public:
    CardBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool card);
    CardBonus(const QJsonObject &json);
    void setCard(std::shared_ptr<Civilisation> card);

    void giveItems(std::shared_ptr<Player> player);

private:
    std::shared_ptr<Civilisation> m_card;
};

#endif // CARDBONUS_H
