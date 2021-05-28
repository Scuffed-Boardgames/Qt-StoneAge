// Denzell Mgbokwere 2054872
#ifndef VARBUILDING_H
#define VARBUILDING_H

#include "building.h"

class VarBuilding : public Building
{
public:
    VarBuilding(int diff, int totalMin, int totalMax);
    VarBuilding(const QJsonObject &json);

    bool build(std::shared_ptr<Player> Player);
    bool build(std::shared_ptr<Player> Player, int woodAmount, int clayAmount, int stoneAmount, int goldAmount);

    bool canPay(std::shared_ptr<Player> player, int woodAmount, int clayAmount, int stoneAmount, int goldAmount);
    int calcScore(int woodAmount, int clayAmount, int stoneAmount, int goldAmount); // Calculates the gained score of a building

    int getDiff() const;
    int getTotalMin() const;
    int getTotalMax() const;

    QJsonObject save();

private:
    int m_diff; // The amount of different resources needed to pay for the building
    int m_totalMin; // The minimum amount of resources you have to pay for a building
    int m_totalMax; // The maximum amount of resources you have to pay for a building (only differs from totalMin for 1-7 building cards)
};
#endif // VARBUILDING_H
