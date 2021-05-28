// Denzell Mgbokwere 2054872
#ifndef SETBUILDING_H
#define SETBUILDING_H

#include "building.h"

class SetBuilding : public Building
{
public:
    SetBuilding(int wood, int clay, int stone, int gold, int score);
    SetBuilding(const QJsonObject &json);

    bool build(std::shared_ptr<Player> player);
    bool canPay(std::shared_ptr<Player> player); // Checks if a player is able to pay for a building

    int getScoreGain() const;
    int getCost(Resource resource) const;

    QJsonObject save();
private:
    int m_woodCost;
    int m_clayCost;
    int m_stoneCost;
    int m_goldCost;
    int m_scoreGain;

};

#endif // SETBUILDING_H
