#ifndef BOARD_H
#define BOARD_H

#include "player.h"
#include "hut.h"
#include "gather.h"
#include "toolshed.h"
#include "field.h"
#include "varbuildingpay.h"
#include "setbuildingpay.h"
#include "setbuilding.h"
#include "varbuilding.h"
#include <memory>

class Board : public QObject
{
    Q_OBJECT
public:
    Board();

    void resetWorkers();
    void feedWorkers();

    std::shared_ptr<Building> getOpenBuildingCard(int pos);
    void newBuilding(int place);
    void rerollBuildings();
    void buildBuilding(Colour colour);

    void nextPlayer(int checked = 0);
    void payResources(Colour colour);
    void addRound();

    std::shared_ptr<ToolShed> getToolShed();
    std::shared_ptr<Hut> getHut();
    std::shared_ptr<Field> getField();
    std::shared_ptr<Player> getPlayer(Colour colour);
    std::shared_ptr<Gather> getGather(Resource resource);
    int getRound() const;
    Colour getCurrentPlayer() const;

    void load(const QJsonObject &json);
    QJsonObject save();

signals:
    void newBuild(std::shared_ptr<Building> building, int pos);
    void allWorkersPlaced();
    void workersReset();
    void roundChanged();

private:

    Colour m_currentPlayer;
    std::vector<std::shared_ptr<Building>> m_buildingCardStacks[4];
    std::shared_ptr<Player> m_players[4];
    std::shared_ptr<Hut> m_hut;
    std::shared_ptr<Gather> m_forest;
    std::shared_ptr<Gather> m_clayPit;
    std::shared_ptr<Gather> m_quarry;
    std::shared_ptr<Gather> m_river;
    std::shared_ptr<Gather> m_hunt;
    std::shared_ptr<ToolShed> m_toolShed;
    std::shared_ptr<Field> m_field;
    int m_round;
    std::shared_ptr<SetBuildingPay> m_setBuildingPay;
    std::shared_ptr<VarBuildingPay> m_varBuildingPay;

};

#endif // BOARD_H
