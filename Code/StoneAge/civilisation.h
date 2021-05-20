#ifndef CIVILISATION_H
#define CIVILISATION_H

#include "civbonuses.h"
#include "player.h"

class Civilisation : public QObject
{
    Q_OBJECT
public:
    Civilisation(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost);

    void addWorker(std::shared_ptr<Player> player);

    void reset();

    virtual void giveItems(std::shared_ptr<Player> player) = 0;
    void giveBonus(std::shared_ptr<Player> player);

    Colour getStandingColour() const;
    int getFarmers() const;
    int getMakers() const;
    int getBuilders() const;
    int getShamen() const;
    CivBonus getBonus() const;
    int getCost() const;

    void setCost(int cost);

    virtual QJsonObject save() = 0;

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
};

#endif // CIVILISATION_H
