#ifndef GATHER_H
#define GATHER_H

#include "place.h"

class Gather : public Place
{
public:
    Gather(Resource resource);
    Resource giveResource(Player player);
    void addWorker(Player player, int amount);
private:
    int m_maxWorkers;
    Resource m_resource;
};

#endif // GATHER_H
