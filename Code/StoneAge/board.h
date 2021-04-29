#ifndef BOARD_H
#define BOARD_H

#include "player.h"
#include "hut.h"
#include "gather.h"
#include "toolshed.h"
#include "field.h"
#include "setbuilding.h"
#include <memory>

class Board : public QObject
{
    Q_OBJECT
public:
    Board();
    void setUpGame();
    void payResources(Colour colour);
    int getTurn();
    std::shared_ptr<Player> getPlayer(Colour colour);
    std::shared_ptr<Gather> getGather(Resource resource);
    void resetWorkers();
    std::shared_ptr<ToolShed> getToolShed();
    std::shared_ptr<Hut> getHut();
    std::shared_ptr<Field> getField();
    void load(const QJsonObject &json);
    QJsonObject save();
    std::shared_ptr<Building> getOpenBuildingCard(int pos);
    void newBuilding(int place);
    void rerollBuildings();
    Colour getCurrentPlayer() const;
    void nextPlayer(int checked = 0);
    void feedWorkers();

    int getRound() const;
    void addRound();

signals:
    void newBuild(std::shared_ptr<Building> building, int pos);
    void allWorkersPlaced();
    void workersReset();
    void roundChanged();
//    void newBuild(std::pair<int, std::shared_ptr<Building>> msg);
private:
    Colour m_currentPlayer;
    std::vector<std::shared_ptr<Building>> m_buildingCards;
    std::shared_ptr<Building> m_openBuildingCards[4];
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
//    std::vector<Building> m_buildings;
};

#endif // BOARD_H
