#ifndef FIELD_H
#define FIELD_H

#include "place.h"

class Field : public Place
{
public:
    Field();
    void giveResource(Player player);
    void addWorker(Player player);
};

#endif // FIELD_H