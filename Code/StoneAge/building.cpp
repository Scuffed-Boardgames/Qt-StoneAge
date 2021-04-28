#include "building.h"

Building::Building() : m_standingColour(Colour::none)
{

}


void Building::addWorker(std::shared_ptr<Player> player){
    if (player->getFreeWorkers() >= 1 && m_standingColour == Colour::none){
        m_standingColour = player->getColour();
        player->setWorkersOccupied(1);
        }
    emit changedWorkers();
}

void Building::reset(){
    m_standingColour = Colour::none;
    emit changedWorkers();
}

Colour Building::getStandingColour() const
{
    return m_standingColour;
}



