#ifndef HUT_H
#define HUT_H

#include "place.h"

class Hut : public Place
{
public:
    Hut();
    Worker giveResource(Player player);
    void addWorker(Player player);
};

#endif // HUT_H
