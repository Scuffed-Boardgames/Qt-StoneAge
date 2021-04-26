#ifndef PLACE_H
#define PLACE_H

#include "player.h"

class Place
{
public:
    Place();
    int removeWorker(Player player, int amount);
private:
    int m_redWorkers;
    int m_blueWorkers;
    int m_yellowWorkers;
    int m_greenWorkers;
};

#endif // PLACE_H
