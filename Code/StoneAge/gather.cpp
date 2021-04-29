#include "gather.h"
#include "rollresources.h"

Gather::Gather(Resource resource) : Place(), m_resource{resource}
{
    if (resource == Resource::food){
        m_maxWorkers = 9999;
    }else{
        m_maxWorkers = 7;
    }
}

void Gather::giveResource(std::shared_ptr<Player> player)
{
    int amount = getWorkers(player->getColour());
    RollResources* roll = new RollResources(amount, m_resource, player, nullptr);
    roll->show();
    if (roll->getGain() > 0){
        player->addResource(m_resource, roll->getGain());
        emit resourcesChanged();
    }
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
    if (player->getFreeWorkers() >= amount && (workerAmount == 0 || m_resource == Resource::food)){
        player->setWorkersOccupied(amount);
        switch(player->getColour()){
        case(Colour::red):
            m_redWorkers += amount;
            break;
        case(Colour::blue):
            m_blueWorkers += amount;
            break;
        case(Colour::yellow):
            m_yellowWorkers += amount;
            break;
        case(Colour::green):
            m_greenWorkers += amount;
            break;
        default:
            return;
        }
        emit changedWorkers();
        emit turnHappend();
    }
}


