#include "gather.h"

Gather::Gather(Resource resource) : Gather::Place(), m_maxWorkers{7}, m_resource{resource}
{}

Resource Gather::giveResource(Player player)
{
    return m_resource;
}

void Gather::addWorker(Player player)
{

}
