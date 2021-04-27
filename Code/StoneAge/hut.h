#ifndef HUT_H
#define HUT_H

#include "place.h"

class Hut : public Place
{
public:
    Hut();
    void giveResource(std::shared_ptr<Player>);
    void addWorker(std::shared_ptr<Player> player, int amount);
};

#endif // HUT_H
