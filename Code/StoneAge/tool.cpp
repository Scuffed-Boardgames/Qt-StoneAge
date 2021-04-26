#include "tool.h"

Tool::Tool() :m_level(0), m_used(false)
{

}

int Tool::getLevel(){
    return m_level;
}

void Tool::levelUp(){
    ++m_level;

}

void Tool::isUsed(){
    m_used = true;
}

bool Tool::wasUsed(){
    return m_used;
}

void Tool::reset(){
     m_used = false;
}
