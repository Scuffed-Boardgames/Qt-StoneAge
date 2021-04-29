#ifndef VARBUILDING_H
#define VARBUILDING_H

#include "building.h"

class VarBuilding : public Building
{
public:
    VarBuilding(int diff, int totalMin, int totalMax);
    void makeBuilding(std::shared_ptr<Player> Player);
    VarBuilding(const QJsonObject &json);
    int getDiff() const;
    bool build(std::shared_ptr<Player> Player, int woodAmount, int clayAmount, int stoneAmount, int goldAmount);

    int getTotalMin() const;
    int getTotalMax() const;

    bool canPay(std::shared_ptr<Player> player, int woodAmount, int clayAmount, int stoneAmount, int goldAmount);
    int calcScore(int woodAmount, int clayAmount, int stoneAmount, int goldAmount);
private:
    int m_diff;
    int m_totalMin;
    int m_totalMax;
};

#endif // VARBUILDING_H
