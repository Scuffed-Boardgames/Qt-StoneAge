// Denzell Mgbokwere 2054872
#ifndef BUILDING_H
#define BUILDING_H

#include "player.h"

class Building : public QObject
{
    Q_OBJECT
public:
    Building();
    Building(Colour colour);

    void addWorker(std::shared_ptr<Player> player); // Adds a worker to the building card

    void reset();
    Colour getStandingColour() const;

    virtual bool build(std::shared_ptr<Player> Player) = 0;
    virtual QJsonObject save() = 0;

signals:
    void changedWorkers();
    void turnHappend();

private:
    Colour m_standingColour;
};

#endif // BUILDING_H
