#include "player.h"

Player::Player() : m_foodCount(12),  m_woodCount(0), m_clayCount(0), m_stoneCount(0), m_goldCount(0), m_scoreCount(0), m_foodGain(0)
{
    for(int i = 0; i < 5 ; ++i ){
        Worker worker(this);
        m_workers.push_back(worker);
    }
}

void Player::addRecourse(Recourse recourse, int amount){
    switch ((int)recourse){
    case(2):
        m_foodCount += amount;
    case(3):
        m_woodCount += amount;
    case(4):
        m_clayCount += amount;
    case(5):
        m_stoneCount += amount;
    case(6):
        m_goldCount += amount;
    default:
        return;
    }
}

void Player::addWorker(){
     Worker worker(this);;
     m_workers.push_back(worker);
}

int Player::getRecourse(Recourse recourse){
    switch ((int)recourse){
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
    return (int)m_workers.size();
}
