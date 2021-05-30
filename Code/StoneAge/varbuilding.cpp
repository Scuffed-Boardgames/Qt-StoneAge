// Denzell Mgbokwere 2054872
#include "varbuilding.h"

VarBuilding::VarBuilding(int diff, int totalMin, int totalMax) : m_diff{diff}, m_totalMin{totalMin}, m_totalMax{totalMax}
{}

VarBuilding::VarBuilding(const QJsonObject &json)
    : Building((Colour)json["colour"].toInt()), m_diff(json["diffMaterials"].toInt()), m_totalMin(json["minCost"].toInt()),m_totalMax(json["maxCost"].toInt())
{}

bool VarBuilding::canPay(std::shared_ptr<Player> player, int woodAmount, int clayAmount, int stoneAmount, int goldAmount){
    if(player->getResource(Resource::wood) < woodAmount)
        return false;
    if(player->getResource(Resource::clay) < clayAmount)
        return false;
    if(player->getResource(Resource::stone) < stoneAmount)
        return false;
    if(player->getResource(Resource::gold) < goldAmount)
        return false;

    return true;
}

int VarBuilding::getDiff() const{
    return m_diff;
}

bool VarBuilding::build(std::shared_ptr<Player> Player){
    return Player == nullptr;
}

int VarBuilding::calcScore(int woodAmount, int clayAmount, int stoneAmount, int goldAmount){
    int score = woodAmount * (int)Resource::wood;
    score += clayAmount * (int)Resource::clay;
    score += stoneAmount * (int)Resource::stone;
    score += goldAmount * (int)Resource::gold;
    return score;
}

QJsonObject VarBuilding::save(){
    QJsonObject json = {{"diffMaterials", m_diff},
                        {"minCost", m_totalMin},
                        {"maxCost", m_totalMax},
                        {"colour", (int)getStandingColour()}};
    return json;
}


bool VarBuilding::build(std::shared_ptr<Player> player, int woodAmount, int clayAmount, int stoneAmount, int goldAmount){
    if(player->getResource(Resource::wood) < woodAmount)
        return false;
    if(player->getResource(Resource::clay) < clayAmount)
        return false;
    if(player->getResource(Resource::stone) < stoneAmount)
        return false;
    if(player->getResource(Resource::gold) < goldAmount)
        return false;
    player->addResource(Resource::wood, -woodAmount);
    player->addResource(Resource::clay, -clayAmount);
    player->addResource(Resource::stone, -stoneAmount);
    player->addResource(Resource::gold, -goldAmount);
    player->addScore(calcScore(woodAmount, clayAmount, stoneAmount, goldAmount));
    player->addBuilding();
    return true;
}



int VarBuilding::getTotalMin() const{
    return m_totalMin;
}

int VarBuilding::getTotalMax() const{
    return m_totalMax;
}
