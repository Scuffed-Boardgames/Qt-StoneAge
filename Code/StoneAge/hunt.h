#ifndef HUNT_H
#define HUNT_H

#include "place.h"

class Hunt : public Place
{
public:
    Hunt();
    Resource giveRecourse(Player player);
    void addWorker(Player player);
private:
    Resource m_resource;
};

#endif // HUNT_H
