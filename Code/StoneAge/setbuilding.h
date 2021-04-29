#ifndef SETBUILDING_H
#define SETBUILDING_H

#include "building.h"

class SetBuilding : public Building
{
public:
    SetBuilding(int wood, int clay, int stone, int gold, int score);
    bool build(std::shared_ptr<Player> Player);
    int getScoreGain() const;

    int getCost(Resource resource) const;
    SetBuilding(const QJsonObject &json);
    SetBuilding(const SetBuilding &building);
    void CopyBuilding(const SetBuilding &building);
    bool canPay(std::shared_ptr<Player>);
private:
    int m_woodCost;
    int m_clayCost;
    int m_stoneCost;
    int m_goldCost;
    int m_scoreGain;

};

#endif // SETBUILDING_H
