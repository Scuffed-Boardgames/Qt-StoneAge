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
    int calcScore(int woodAmount, int clayAmount, int stoneAmount, int goldAmount);

    int getDiff() const;
    int getTotalMin() const;
    int getTotalMax() const;

    QJsonObject save();

private:
    int m_diff;
    int m_totalMin;
    int m_totalMax;
};

#endif // VARBUILDING_H
