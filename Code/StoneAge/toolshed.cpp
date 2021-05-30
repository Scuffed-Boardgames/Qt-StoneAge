// Bernd Uijtdebroeks 2055267
#include "toolshed.h"

ToolShed::ToolShed() : Place(), m_tools34(6)
{

}


void ToolShed::giveResource(std::shared_ptr<Player> player){
    int amount = getWorkers(player->getColour());

    if(player->getLowestToolLevel() == 2 ){
        if(m_tools34 <= 0){
            return;
        }else {
            --m_tools34;
        }
    }

    if(amount == 1){
        player->addTool();
    }
}

void ToolShed::addWorker(std::shared_ptr<Player> player, int amount){
    amount = 1;
    if(m_redWorkers != 0 or m_blueWorkers != 0 or m_yellowWorkers != 0 or m_greenWorkers != 0)
        return;
    if(player->getFreeWorkers() < amount)
        return;
    if(player->maxToolsReached())
        return;
    player->setWorkersOccupied(amount);
    switch(player->getColour()){
    case(Colour::red):
        m_redWorkers = amount;
        break;
    case(Colour::blue):
        m_blueWorkers = amount;
        break;
    case(Colour::yellow):
        m_yellowWorkers = amount;
        break;
    case(Colour::green):
        m_greenWorkers = amount;
        break;
    default:
        return;
    }
    emit changedWorkers();
    emit turnHappend();
}

int ToolShed::getTools34() const
{
    return m_tools34;
}
