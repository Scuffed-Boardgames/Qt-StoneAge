#include "gather.h"

Gather::Gather(Resource resource) : Place(), m_resource{resource}
{
    if (resource == Resource::food){
        m_maxWorkers = 99;
    }else{
        m_maxWorkers = 7;
    }
}

Resource Gather::giveResource(std::shared_ptr<Player> player)
{
    return m_resource;
}

void Gather::addWorker(std::shared_ptr<Player> player, int amount)
{
    int workerAmount;
    switch(player->getColour()){
    case(Colour::red):
        workerAmount = m_redWorkers;
        break;
    case(Colour::blue):
        workerAmount = m_blueWorkers;
        break;
    case(Colour::yellow):
        workerAmount = m_yellowWorkers;
        break;
    case(Colour::green):
        workerAmount = m_greenWorkers;
        break;
    default:
        return;
    }
    if (player->getAmountFreeWorkers() >= amount && (workerAmount == 0 || m_resource == Resource::food)){
        std::vector<Worker*> workers = player->getFreeWorkers();
        for (int i = 0; i<amount ; ++i){
            workers[i]->setOccupation(this);
        }
    }
}
