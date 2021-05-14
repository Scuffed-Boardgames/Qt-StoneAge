#include "civilisation.h"

Civilisation::Civilisation(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost)
    : m_standingColour(colour), m_farmers(farmers), m_makers(makers), m_builders(builders), m_shamen(shamen), m_bonus(bonus), m_cost(cost){
}

void Civilisation::addWorker(std::shared_ptr<Player> player){
    if (player->getFreeWorkers() >= 1 && m_standingColour == Colour::none){
        m_standingColour = player->getColour();
        player->setWorkersOccupied(1);
        emit changedWorkers();
        emit turnHappend();
    }
}

void Civilisation::reset(){
    m_standingColour = Colour::none;
    emit changedWorkers();
}

Colour Civilisation::getStandingColour() const
{
    return m_standingColour;
}

void Civilisation::giveBonus(std::shared_ptr<Player> player)
{
//    player->addBonus(m_farmers, m_makers, m_builders, m_shamen, m_bonus);
}

int Civilisation::getCost() const
{
    return m_cost;
}

void Civilisation::setCost(int cost)
{
    m_cost = cost;
}

int Civilisation::getFarmers() const
{
    return m_farmers;
}

int Civilisation::getMakers() const
{
    return m_makers;
}

int Civilisation::getBuilders() const
{
    return m_builders;
}

int Civilisation::getShamen() const
{
    return m_shamen;
}

CivBonus Civilisation::getBonus() const
{
    return m_bonus;
}
