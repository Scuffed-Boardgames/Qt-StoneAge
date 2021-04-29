#include "setbuilding.h"

SetBuilding::SetBuilding(int wood, int clay, int stone, int gold, int score) : m_woodCost(wood), m_clayCost(clay), m_stoneCost(stone), m_goldCost(gold), m_scoreGain(score)
{
}

SetBuilding::SetBuilding(const QJsonObject & json)
    :m_woodCost((int)json["woodCost"].toDouble()), m_clayCost((int)json["clayCost"].toDouble()),
      m_stoneCost((int)json["stoneCost"].toDouble()), m_goldCost((int)json["goldCost"].toDouble()), m_scoreGain((int)json["scoreGain"].toDouble())
{
}

//SetBuilding::SetBuilding(const SetBuilding & building)
//    : m_woodCost(building.getCost(Resource::wood)), m_clayCost(building.getCost(Resource::clay)),
//      m_stoneCost(building.getCost(Resource::stone)), m_goldCost(building.getCost(Resource::gold)), m_scoreGain(getScoreGain())
//{
//}

//void SetBuilding::CopyBuilding(const SetBuilding & building){
//    m_woodCost = building.getCost(Resource::wood);
//    m_clayCost = building.getCost(Resource::clay);
//    m_stoneCost = building.getCost(Resource::stone);
//    m_goldCost = building.getCost(Resource::gold);
//    m_scoreGain = getScoreGain();
//}

void SetBuilding::build(std::shared_ptr<Player> player){
    if(player->getResource(Resource::wood) < m_woodCost)
        return;
    if(player->getResource(Resource::clay) < m_clayCost)
        return;
    if(player->getResource(Resource::stone) < m_stoneCost)
        return;
    if(player->getResource(Resource::gold) < m_goldCost)
        return;
    player->addResource(Resource::wood, -m_woodCost);
    player->addResource(Resource::clay, -m_clayCost);
    player->addResource(Resource::stone, -m_stoneCost);
    player->addResource(Resource::gold, -m_goldCost);
    player->addScore(m_scoreGain);
}

int SetBuilding::getScoreGain() const
{
    return m_scoreGain;
}

int SetBuilding::getCost(Resource resource) const
{
    switch (resource){
    case(Resource::wood):
        return m_woodCost;
    case(Resource::clay):
        return m_clayCost;
    case(Resource::stone):
        return m_stoneCost;
    case(Resource::gold):
        return m_goldCost;
    default:
        return 0;
    }
}