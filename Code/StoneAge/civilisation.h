#ifndef CIVILISATION_H
#define CIVILISATION_H

#include "civbonuses.h"
#include "player.h"

class Civilisation : public QObject
{
    Q_OBJECT
public:
    Civilisation(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, bool card);

    void addWorker(std::shared_ptr<Player> player);

    void reset();
    Colour getStandingColour() const;

    virtual void giveItems(std::shared_ptr<Player> player) = 0;
    void giveBonus(std::shared_ptr<Player> player);

    int getCost() const;
    void setCost(int cost);

signals:
    void changedWorkers();
    void turnHappend();

private:
    Colour m_standingColour;

    int m_farmers;
    int m_makers;
    int m_builders;
    int m_shamen;
    CivBonus m_bonus;

    int m_cost;

    bool m_card;

};

#endif // CIVILISATION_H
