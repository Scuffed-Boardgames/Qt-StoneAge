#include "worker.h"


Worker::Worker(void* owner) : m_owner(owner), m_occupied(false)
{

}

void Worker::setOccupied(){
    m_occupied = true;
}

bool Worker::isOccupied(){
    return m_occupied;
}

void Worker::reset(){
     m_occupied = false;
}
