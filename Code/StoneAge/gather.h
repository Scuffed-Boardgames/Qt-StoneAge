#ifndef GATHER_H
#define GATHER_H

#include "place.h"

class Gather : public Place
{
public:
    Gather(Resource resource);
    Resource giveResource(std::shared_ptr<Player>);
    void addWorker(std::shared_ptr<Player>, int amount);
private:
    int m_maxWorkers;
    Resource m_resource;
};

#endif // GATHER_H
