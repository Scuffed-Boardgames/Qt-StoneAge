#ifndef PLACE_H
#define PLACE_H

#include "player.h"
#include <memory>

class Place
{
public:
    Place();
    int removeWorker();
    virtual void addWorker(std::shared_ptr<Player>, int amount);
    int getWorkers(Colour colour);
protected:
    int m_redWorkers;
    int m_blueWorkers;
    int m_yellowWorkers;
    int m_greenWorkers;
};

#endif // PLACE_H
