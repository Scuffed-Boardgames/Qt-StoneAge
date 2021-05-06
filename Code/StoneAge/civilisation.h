#ifndef CIVILISATION_H
#define CIVILISATION_H

#include "civbonuses.h"
#include "player.h"

class Civilisation : public QObject
{
    Q_OBJECT
public:
    Civilisation(int farmers, int makers, int builders, int shamen, CivBonus bonus);

    void addWorker(std::shared_ptr<Player> player);

    void reset();
    Colour getStandingColour() const;

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

};

#endif // CIVILISATION_H
