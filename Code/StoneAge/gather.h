// Bernd Uijtdebroeks 2055267
#ifndef GATHER_H
#define GATHER_H

#include "place.h"

class Gather : public Place
{
public:
    Gather(Resource resource);
    void giveResource(std::shared_ptr<Player>);
    void addWorker(std::shared_ptr<Player>, int amount);

    int getMaxWorkers() const;
private:
    int m_maxWorkers;
    Resource m_resource;
};

#endif // GATHER_H
