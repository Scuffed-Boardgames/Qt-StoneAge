// Denzell Mgbokwere 2054872
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

QJsonObject Tool::save(){
    QJsonObject json = {{"level", m_level},
                        {"used", m_used}};
    return json;
}

Tool::Tool(const QJsonObject & tool){
    if(tool.contains("level") && tool["level"].isDouble()){
        m_level = (int)tool["level"].toDouble();
    }
    if(tool.contains("used") && tool["used"].isBool()){
        m_used = tool["used"].toBool();
    }
}
