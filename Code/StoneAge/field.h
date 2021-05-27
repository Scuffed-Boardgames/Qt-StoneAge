// Bernd Uijtdebroeks 2055267
#ifndef FIELD_H
#define FIELD_H

#include "place.h"

class Field : public Place
{
public:
    Field();
    void giveResource(std::shared_ptr<Player> player);
    void addWorker(std::shared_ptr<Player> player, int amount);
};

#endif // FIELD_H
