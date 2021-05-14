#ifndef TOOLSHED_H
#define TOOLSHED_H

#include "place.h"

class ToolShed : public Place
{
public:
    ToolShed();
    void giveResource(std::shared_ptr<Player> player);
    void addWorker(std::shared_ptr<Player> player, int amount = 1);
    int getTools34() const;

private:
    int m_tools34;
};

#endif // TOOLSHED_H
