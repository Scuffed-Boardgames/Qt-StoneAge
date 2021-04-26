#ifndef TOOLSHED_H
#define TOOLSHED_H

#include "place.h"

class ToolShed : public Place
{
public:
    ToolShed();
    void giveResource(std::shared_ptr<Player> player);
    void addWorker(std::shared_ptr<Player> player, int amount = 1);
};

#endif // TOOLSHED_H
