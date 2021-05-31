// Denzell Mgbokwere 2054872
#include "player.h"

#include <QJsonArray>

Player::Player(): m_foodCount(12),  m_woodCount(0), m_clayCount(0), m_stoneCount(0), m_goldCount(0), m_buildingCount(0),
    m_scoreCount(0), m_foodGain(0), m_colour(Colour::none), m_freeWorkers(5), m_workers(5), m_farmerCount(0), m_toolMakerCount(0), m_hutBuilderCount(0), m_shamanCount(0)
{}

Player::Player(Colour colour) : m_foodCount(12),  m_woodCount(0), m_clayCount(0), m_stoneCount(0), m_goldCount(0), m_buildingCount(0),
    m_scoreCount(0), m_foodGain(0), m_colour(colour), m_freeWorkers(5), m_workers(5), m_farmerCount(0), m_toolMakerCount(0), m_hutBuilderCount(0), m_shamanCount(0)
{
    for(int i = 0; i < 8 ; ++i){
        m_civBonuses[i] = 0;
    }
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
    emit dataChanged();
}

void Player::addFoodGain(){
    m_foodGain += 1;
    emit dataChanged();
}

void Player::addBuilding(){
    m_buildingCount += 1;
    emit dataChanged();
}

void Player::addExtraTool(int tool)
{
    m_extraTools.push_back(tool);
}

void Player::addBonus(int farmers, int makers, int builders, int shamen, CivBonus bonus)
{
    m_farmerCount += farmers;
    m_toolMakerCount += makers;
    m_hutBuilderCount += builders;
    m_shamanCount += shamen;
    switch (bonus){
    case(CivBonus::art):
        m_civBonuses[0] += 1;
        return;
    case(CivBonus::healing):
        m_civBonuses[1] += 1;
        return;
    case(CivBonus::music):
        m_civBonuses[2] += 1;
        return;
    case(CivBonus::pottery):
        m_civBonuses[3] += 1;
        return;
    case(CivBonus::time):
        m_civBonuses[4] += 1;
        return;
    case(CivBonus::transport):
        m_civBonuses[5] += 1;
        return;
    case(CivBonus::weaving):
        m_civBonuses[6] += 1;
        return;
    case(CivBonus::writing):
        m_civBonuses[7] += 1;
        return;
    default:
        return;
    }
}

Tool *Player::getTools(){
    return m_tools;
}

int Player::getLowestToolLevel(){
    int lowestLevel = 5;
    for(int i = 0; i < 3; ++i){
        if(m_tools[i].getLevel() < lowestLevel)
            lowestLevel = m_tools[i].getLevel();
    }
    return lowestLevel;

}

int Player::getBuildingCount() const
{
    return m_buildingCount;
}

std::vector<int> Player::getExtraTools() const
{
    return m_extraTools;
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
    m_foodCount = json["food"].toInt();
    m_woodCount = json["wood"].toInt();
    m_clayCount = json["clay"].toInt();
    m_stoneCount = json["stone"].toInt();
    m_goldCount = json["gold"].toInt();
    m_scoreCount = json["score"].toInt();
    m_foodGain = json["foodGain"].toInt();
    m_farmerCount = json["farmers"].toInt();
    m_toolMakerCount = json["toolMakers"].toInt();
    m_hutBuilderCount = json["hutBuilders"].toInt();
    m_shamanCount = json["shamans"].toInt();
    m_buildingCount = json["buildings"].toInt();
    m_colour = (Colour)json["colour"].toInt();
    m_workers = json["workerTotal"].toInt();
    m_freeWorkers = json["workerFree"].toInt();

    QJsonArray tools = json["tools"].toArray();
    for (int i = 0; i < tools.size(); ++i) {
        QJsonObject tool = tools[i].toObject();
        m_tools[i] = Tool(tool);
    }
    QJsonArray extraTools = json["extraTools"].toArray();
     m_extraTools.clear();
    for (int i = 0; i < extraTools.size(); ++i) {
        m_extraTools.push_back(extraTools[i].toInt());
    }

    QJsonArray civBonuses = json["civBonuses"].toArray();
    for (int i = 0; i < civBonuses.size(); ++i) {
        civBonuses[i] = civBonuses[i].toInt();
    }
    emit dataChanged();
}

QJsonObject Player::save(){
    QJsonArray tools;
    for (int i = 0; i < 3; ++i) {
        tools.append(m_tools[i].save());
    }
    QJsonArray extraTools;
    for (size_t i = 0; i < m_extraTools.size();++i){
        extraTools.append(m_extraTools[i]);
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
                        {"extraTools", extraTools},
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

bool Player::maxToolsReached()
{
    int total = m_tools[0].getLevel() + m_tools[1].getLevel() + m_tools[2].getLevel();
    if (total >= 12){
        return true;
    }
    return false;
}

void Player::deleteExtraTool(int tool){
    for(size_t i = 0; i < m_extraTools.size(); ++i){
        if(tool == m_extraTools[i]){
            m_extraTools.erase(m_extraTools.begin() + i);
            return;
        }
    }
}

int Player::calcScore(){
    int score = m_scoreCount;
    score += m_farmerCount * m_foodGain;
    score += m_hutBuilderCount * m_buildingCount;
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

    tieBreak += toolAmount;
    return tieBreak;
}
