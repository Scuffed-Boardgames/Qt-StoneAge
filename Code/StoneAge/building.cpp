// Denzell Mgbokwere 2054872
#include "building.h"

Building::Building() : m_standingColour(Colour::none)
{}

Building::Building(Colour colour) : m_standingColour(colour)
{}


void Building::addWorker(std::shared_ptr<Player> player){
    if (player->getFreeWorkers() >= 1 && m_standingColour == Colour::none){
        m_standingColour = player->getColour();
        player->setWorkersOccupied(1);
        emit changedWorkers();
        emit turnHappend();
    }
}


void Building::reset(){
    m_standingColour = Colour::none;
    emit changedWorkers();
}


Colour Building::getStandingColour() const
{
    return m_standingColour;
}




