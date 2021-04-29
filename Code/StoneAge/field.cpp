#include "field.h"

Field::Field() : Place()
{

}

void Field::giveResource(std::shared_ptr<Player> player)
{
    int amount = getWorkers(player->getColour());
    if(amount == 1){
        player->addFoodGain();
        emit resourcesChanged();
    }
}

void Field::addWorker(std::shared_ptr<Player> player, int amount = 1)
{
    if(m_redWorkers != 0 or m_blueWorkers != 0 or m_yellowWorkers != 0 or m_greenWorkers != 0)
        return;
    if(player->getFreeWorkers() < amount)
        return;
    player->setWorkersOccupied(amount);
    switch(player->getColour()){
    case(Colour::red):
        m_redWorkers = amount;
        break;
    case(Colour::blue):
        m_blueWorkers = amount;
        break;
    case(Colour::yellow):
        m_yellowWorkers = amount;
        break;
    case(Colour::green):
        m_greenWorkers = amount;
        break;
    default:
        return;
    }
    emit changedWorkers();
    emit turnHappend();
}


