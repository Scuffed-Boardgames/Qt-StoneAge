#include "hunt.h"

Hunt::Hunt() : Hunt::Place(), m_resource{Resource::food}
{

}

Resource Hunt::giveRecourse(Player player)
{
    return Resource::food;
}


void Hunt::addWorker(Player player)
{

}
