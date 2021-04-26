#include "worker.h"


Worker::Worker(void* owner) : m_owner(owner), m_occupation(nullptr)
{

}

void* Worker::getOccupation()
{
    return m_occupation;

}

void Worker::setOccupation(void *occupation)
{
    m_occupation = occupation;
}

void Worker::setOccupation()
{
    m_occupation = nullptr;
}
