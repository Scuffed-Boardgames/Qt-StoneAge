#include "gather.h"

Gather::Gather(Resource resource) : Place(), m_resource{resource}
{
    if (resource == Resource::food){
        m_maxWorkers = 99;
    }else{
        m_maxWorkers = 7;
    }
}

Resource Gather::giveResource(Player player)
{
    return m_resource;
}

void Gather::addWorker(Player player)
{

}
