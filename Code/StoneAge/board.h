#ifndef BOARD_H
#define BOARD_H

#include "player.h"
#include "hut.h"
#include "gather.h"
#include "toolshed.h"
#include "field.h"
#include <memory>

class Board
{
public:
    Board();
    void setUpGame();
    void playTurn();
    int getTurn();
    std::shared_ptr<Player> getPlayer(Colour colour);
    Gather* getGather(Resource resource);
    void resetWorkers();
    ToolShed* getToolShed();
    void load(const QJsonObject &json);
    QJsonObject save();
private:
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
