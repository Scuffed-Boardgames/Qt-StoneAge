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

    bool getEnded() const;

    bool checkStacks();
    void end();
signals:
    void newBuild(std::shared_ptr<Building> building, int pos);
    void allWorkersPlaced();
    void workersReset();
    void roundChanged();
    void endGame();

private:
    bool m_ended; //saved & loaded
    Colour m_currentPlayer; //saved & loaded
    std::vector<std::shared_ptr<Building>> m_buildingCardStacks[4]; //saved & loaded
    std::shared_ptr<Player> m_players[4]; //saved & loaded
    std::shared_ptr<Hut> m_hut; //saved & loaded
    std::shared_ptr<Gather> m_forest; //saved & loaded
    std::shared_ptr<Gather> m_clayPit; //saved & loaded
    std::shared_ptr<Gather> m_quarry; //saved & loaded
    std::shared_ptr<Gather> m_river; //saved & loaded
    std::shared_ptr<Gather> m_hunt; //saved & loaded
    std::shared_ptr<ToolShed> m_toolShed; //saved & loaded
    std::shared_ptr<Field> m_field; //saved & loaded
    int m_round; //saved & loaded
    std::shared_ptr<SetBuildingPay> m_setBuildingPay; //doesnt need to be saved or loaded
    std::shared_ptr<VarBuildingPay> m_varBuildingPay; //doesnt need to be saved or loaded

};

#endif // BOARD_H
