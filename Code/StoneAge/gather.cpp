#include "gather.h"

Gather::Gather(Resource resource) : Place(), m_resource{resource}
{
    if (resource == Resource::food){
        m_maxWorkers = 99;
    }else{
        m_maxWorkers = 7;
    }
}

Resource Gather::giveResource(Player player)
{
    return m_resource;
}

void Gather::addWorker(Player player, int amount)
{
    int workerAmount;
    switch(player.getColour()){
    case(Colour::red):
        workerAmount = m_redWorkers;
        return;
    case(Colour::blue):
        return;
    case(Colour::yellow):
        return;
    case(Colour::green):
        return;
    default:
        return;
    }
    if (player.getAmountFreeWorkers() >= amount){
        std::vector<Worker*> workers = player.getFreeWorkers();
        for (int i = 0; i<amount ; ++i){
            workers[i]->setOccupation(this);
        }
    }else{

    }
}
