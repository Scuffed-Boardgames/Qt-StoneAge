// Bernd Uijtdebroeks 2055267
#ifndef HUT_H
#define HUT_H

#include "place.h"

class Hut : public Place
{
public:
    Hut();
    void giveResource(std::shared_ptr<Player>); // Gives a worker to the player
    void addWorker(std::shared_ptr<Player> player, int amount);
};

#endif // HUT_H
