#include "player.h"

Player::Player(): m_foodCount(12),  m_woodCount(0), m_clayCount(0), m_stoneCount(0), m_goldCount(0), m_buildingCount(0),
    m_scoreCount(0), m_foodGain(0), m_colour(Colour::none), m_freeWorkers(5), m_workers(5), m_farmerCount(0), m_toolMakerCount(0), m_hutBuilderCount(0), m_shamanCount(0)
{}

Player::Player(Colour colour) : m_foodCount(12),  m_woodCount(0), m_clayCount(0), m_stoneCount(0), m_goldCount(0), m_buildingCount(0),
    m_scoreCount(0), m_foodGain(0), m_colour(colour), m_freeWorkers(5), m_workers(5), m_farmerCount(0), m_toolMakerCount(0), m_hutBuilderCount(0), m_shamanCount(0)
{}


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

void Player::addTool(){
    int lowestLevel = m_tools[0].getLevel();
    int lowestLevelPos = 0;
    for(int i = 1; i < 3; ++i){
        if(m_tools[i].getLevel() < lowestLevel){
            lowestLevel = m_tools[i].getLevel();
            lowestLevelPos = i;
        }
    }
    m_tools[lowestLevelPos].levelUp();
    emit dataChanged();
}

void Player::addScore(int amount){
    m_scoreCount += amount;
}

void Player::addFoodGain(){
    m_foodGain += 1;
}

void Player::addBuilding(){
    m_buildingCount += 1;
}


Tool *Player::getTools(){
    return m_tools;
}

int Player::getResource(const Resource resource){
    switch (resource){
    case(Resource::food):
        return m_foodCount;
    case(Resource::wood):
        return m_woodCount;
    case(Resource::clay):
        return m_clayCount;
    case(Resource::stone):
        return m_stoneCount;
    case(Resource::gold):
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


void Player::resetTools()
{
    for(int i = 0; i < 3; ++i){
        m_tools[i].reset();
    }
}

void Player::resetWorkers(){
    m_freeWorkers = m_workers;
    emit dataChanged();
}


void Player::setWorkersOccupied(int amount){
    m_freeWorkers -= amount;
    emit dataChanged();
}

void Player::disableTool(int nr){
    m_tools[nr].isUsed();
}


void Player::load(const QJsonObject &json){
    m_foodCount = (int)json["food"].toDouble();
    m_woodCount = (int)json["wood"].toDouble();
    m_clayCount = (int)json["clay"].toDouble();
    m_stoneCount = (int)json["stone"].toDouble();
    m_goldCount = (int)json["gold"].toDouble();
    m_scoreCount = (int)json["score"].toDouble();
    m_foodGain = (int)json["foodGain"].toDouble();
    m_farmerCount = (int)json["farmers"].toDouble();
    m_toolMakerCount = (int)json["toolMakers"].toDouble();
    m_hutBuilderCount = (int)json["hutBuilders"].toDouble();
    m_shamanCount = (int)json["shamans"].toDouble();
    m_buildingCount = (int)json["buildings"].toDouble();
    m_colour = (Colour)(int)json["colour"].toDouble();
    m_workers = (int)json["workerTotal"].toDouble();
    m_freeWorkers = (int)json["workerFree"].toDouble();

    QJsonArray tools = json["tools"].toArray();
    for (int i = 0; i < tools.size(); ++i) {
        QJsonObject tool = tools[i].toObject();
        m_tools[i] = Tool(tool);
    }

    QJsonArray civBonuses = json["civBonuses"].toArray();
    for (int i = 0; i < civBonuses.size(); ++i) {
        civBonuses[i] = (int)civBonuses[i].toDouble();
    }
    emit dataChanged();
}

QJsonObject Player::save(){
    QJsonArray tools;
    for (int i = 0; i < 3; ++i) {
        tools.append(m_tools[i].save());
    }

    QJsonArray civBonuses;
    for (int i = 0; i < 8; ++i) {
        civBonuses.append(m_civBonuses[i]);
    }
    QJsonObject json = {{"food", m_foodCount},
                        {"wood", m_woodCount},
                        {"clay", m_clayCount},
                        {"stone", m_stoneCount},
                        {"gold", m_goldCount},
                        {"score", m_scoreCount},
                        {"foodGain", m_foodGain},
                        {"farmers", m_farmerCount},
                        {"toolMakers", m_toolMakerCount},
                        {"hutBuilders", m_hutBuilderCount},
                        {"shamans", m_shamanCount},
                        {"buildings", m_buildingCount},
                        {"colour", (int)m_colour},
                        {"workerTotal", m_workers},
                        {"workerFree", m_freeWorkers},
                        {"tools", tools},
                        {"civBonuses", civBonuses}};
    return json;
}

QString Player::getString(){
    switch(m_colour){
    case(Colour::red):
        return "Red player";
    case(Colour::blue):
        return "Blue player";
    case(Colour::yellow):
        return "Yellow player";
    case(Colour::green):
        return "Green player";
    default:
        return "error: no colour given";
    }
}

int Player::calcScore(){
    int score = m_scoreCount;
    score += m_farmerCount * m_foodGain;
    score += m_shamanCount * m_workers;
    int toolAmount = 0;
    for(Tool tool : m_tools){
        toolAmount += tool.getLevel();
    }
    score += m_toolMakerCount * toolAmount;
    int c = 1;
    while(c != 0){
        c = 0;
        for(int i = 0; i < 8; ++i){
            if(m_civBonuses[i] > 0){
                ++c;
                m_civBonuses[i] -= 1;
            }

        }
        score += std::pow(c, 2);
    }
    return score;
}

int Player::calcTieBreak(){
    int tieBreak = m_foodGain;
    tieBreak += m_workers;

    int toolAmount = 0;
    for(Tool tool : m_tools){
        toolAmount += tool.getLevel();
    }

    tieBreak += m_toolMakerCount * toolAmount;
    return tieBreak;
}
