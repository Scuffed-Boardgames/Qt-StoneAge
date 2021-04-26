#include "player.h"

Player::Player(): m_foodCount(12),  m_woodCount(0), m_clayCount(0), m_stoneCount(0), m_goldCount(0), m_scoreCount(0), m_foodGain(0), m_colour(Colour::none), m_freeWorkers(5), m_workers(5)
{

}

Player::Player(Colour colour) : m_foodCount(12),  m_woodCount(0), m_clayCount(0), m_stoneCount(0), m_goldCount(0), m_scoreCount(0), m_foodGain(0), m_colour(colour), m_freeWorkers(5), m_workers(5)
{

}

void Player::addResource(const Resource resource, const int amount){
    switch (resource){
    case(Resource::food):
        m_foodCount += amount;
        break;
    case(Resource::wood):
        m_woodCount += amount;
        break;
    case(Resource::clay):
        m_clayCount += amount;
        break;
    case(Resource::stone):
        m_stoneCount += amount;
        break;
    case(Resource::gold):
        m_goldCount += amount;
        break;
    default:
        break;
    }
    emit dataChanged();
}

void Player::addWorker(){
    ++m_freeWorkers;
    ++m_workers;
    emit dataChanged();
}

int Player::getResource(const Resource resource){
    switch ((int)resource){
    case(2):
        return m_foodCount;
    case(3):
        return m_woodCount;
    case(4):
        return m_clayCount;
    case(5):
        return m_stoneCount;
    case(6):
        return m_goldCount;
    default:
        return 0;
    }
}

int Player::getScore(){
    return m_scoreCount;
}

int Player::getFoodGain(){
    return m_foodGain;
}
int Player::getWorkerCount(){
    return m_workers;
}

int Player::getFreeWorkers()
{
    return m_freeWorkers;
}


Colour Player::getColour() const
{
    return m_colour;
}

void Player::reset()
{
    m_freeWorkers = m_workers;
    emit dataChanged();
}

void Player::setWorkersOccupied(int amount){
    m_freeWorkers -= amount;
    emit dataChanged();
}

