#ifndef BUILDING_H
#define BUILDING_H

#include "colour.h"
#include "player.h"

class Building : public QObject
{
    Q_OBJECT
public:
    Building(const QJsonObject &json);
    Building();
    void addWorker(std::shared_ptr<Player> player);
    void reset();
    Colour getStandingColour() const;
    virtual bool build(std::shared_ptr<Player> Player) = 0;
signals:
    void changedWorkers();
private:
    Colour m_standingColour;
};

#endif // BUILDING_H
