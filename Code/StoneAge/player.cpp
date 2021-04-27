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

int Player::getFreeWorkers(){
    return m_freeWorkers;
}


Colour Player::getColour() const{
    return m_colour;
}

void Player::reset(){
    m_freeWorkers = m_workers;
    emit dataChanged();
}

void Player::setWorkersOccupied(int amount){
    m_freeWorkers -= amount;
    emit dataChanged();
}

Tool *Player::getTools(){
    return m_tools;
}

void Player::addTool(){
    int lowestLevel = m_tools[0].getLevel();
    int lowestLevelPos = 0;
    for(int i = 1; i > 3; ++i){
        if(m_tools[i].getLevel() < lowestLevel){
            lowestLevel = m_tools[i].getLevel();
            lowestLevelPos = i;
        }
    }
    m_tools[lowestLevelPos].levelUp();
    emit dataChanged();
}

void Player::disableTool(int nr){
    m_tools[nr].isUsed();
}

void Player::load(const QJsonObject &json){
//    if(json.contains("food") && json["food"].isDouble()){
        m_foodCount = (int)json["food"].toDouble();
//    }
//    if(json.contains("wood") && json["wood"].isDouble()){
        m_woodCount = (int)json["wood"].toDouble();

//    }
//    if(json.contains("clay") && json["clay"].isDouble()){
        m_clayCount = (int)json["clay"].toDouble();

//    }
//    if(json.contains("stone") && json["stone"].isDouble()){
        m_stoneCount = (int)json["stone"].toDouble();

//    }
//    if(json.contains("gold") && json["gold"].isDouble()){
        m_goldCount = (int)json["gold"].toDouble();

//    }
//    if(json.contains("score") && json["score"].isDouble()){
        m_scoreCount = (int)json["score"].toDouble();

//    }
//    if(json.contains("foodGain") && json["foodGain"].isDouble()){
        m_foodGain = (int)json["foodGain"].toDouble();

//    }
//    if(json.contains("colour") && json["colour"].isDouble()){
        m_colour = (Colour)(int)json["colour"].toDouble();

//    }
//    if(json.contains("workerTotal") && json["workerTotal"].isDouble()){
        m_workers = (int)json["workerTotal"].toDouble();
//    }
//    if(json.contains("workerFree") && json["workerFree"].isDouble()){
        m_freeWorkers = (int)json["workerFree"].toDouble();
//    }
//    if(json.contains("tools") && json["tools"].isArray()){
        QJsonArray tools = json["tools"].toArray();
        for (int i = 0; i < tools.size(); ++i) {
            QJsonObject tool = tools[i].toObject();
            m_tools[i] = Tool(tool);
            }
//    }
}

QJsonObject Player::save(){
    QJsonArray tools;
    for (int i = 0; i < 3; ++i) {
         tools.append(m_tools[i].save());
         }
   QJsonObject json = {{"food", m_foodCount},
                       {"wood", m_woodCount},
                       {"clay", m_clayCount},
                       {"stone", m_stoneCount},
                       {"gold", m_goldCount},
                       {"score", m_scoreCount},
                       {"foodGain", m_foodGain},
                       {"colour", (int)m_colour},
                       {"workerTotal", m_workers},
                       {"workerFree", m_freeWorkers},
                       {"tools", tools}};
   return json;
}
