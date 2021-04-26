#ifndef TOOLSHED_H
#define TOOLSHED_H

#include "place.h"

class Toolshed : public Place
{
public:
    Toolshed();
    void giveResource(Player player);
    void addWorker(Player player);
};

#endif // TOOLSHED_H
