#ifndef TOOLSHED_H
#define TOOLSHED_H

#include "place.h"

class Toolshed : public Place
{
public:
    Toolshed();
    void giveResource(std::shared_ptr<Player> player);
    void addWorker(std::shared_ptr<Player> player, int amount);
};

#endif // TOOLSHED_H
