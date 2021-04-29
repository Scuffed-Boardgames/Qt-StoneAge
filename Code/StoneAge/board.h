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
    Gather* getGather(Resource resource);
    void resetWorkers();
    ToolShed* getToolShed();
    Hut* getHut();
    Field* getField();
    void load(const QJsonObject &json);
    QJsonObject save();
    std::shared_ptr<Building> getOpenBuildingCard(int pos);
    void newBuilding(int place);
    void rerollBuildings();
    Colour getCurrentPlayer() const;
    void nextPlayer(int checked = 0);

signals:
    void newBuild(std::shared_ptr<Building> building, int pos);
    void allWorkersPlaced();
//    void newBuild(std::pair<int, std::shared_ptr<Building>> msg);
private:
    Colour m_currentPlayer;
    std::vector<std::shared_ptr<Building>> m_buildingCards;
    std::shared_ptr<Building> m_openBuildingCards[4];
    std::shared_ptr<Player> m_players[4];
    Hut m_hut;
    Gather m_forest;
    Gather m_clayPit;
    Gather m_quarry;
    Gather m_river;
    Gather m_hunt;
    ToolShed m_toolShed;
    Field m_field;
    int m_turn;
//    std::vector<Building> m_buildings;
};

#endif // BOARD_H
