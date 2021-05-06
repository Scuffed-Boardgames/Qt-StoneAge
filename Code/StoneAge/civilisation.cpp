#include "civilisation.h"

Civilisation::Civilisation(int farmers, int makers, int builders, int shamen, CivBonus bonus)
    : m_standingColour(Colour::none), m_farmers(farmers), m_makers(makers), m_builders(builders), m_shamen(shamen), m_bonus(bonus)
{}

void Civilisation::addWorker(std::shared_ptr<Player> player)
{
    if (player->getFreeWorkers() >= 1 && m_standingColour == Colour::none){
        m_standingColour = player->getColour();
        player->setWorkersOccupied(1);
    }
}

void Civilisation::reset()
{
    m_standingColour = Colour::none;
    emit changedWorkers();
}

Colour Civilisation::getStandingColour() const
{
    return m_standingColour;
}
