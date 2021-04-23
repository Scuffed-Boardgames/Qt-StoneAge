#ifndef BOARD_H
#define BOARD_H

#include "player.h"
#include <memory>

class Board
{
public:
    Board();
    void setUpGame();
    void playTurn();
    int getTurn();
    std::shared_ptr<Player> getPlayer(int nr);
private:
    Player m_players[4];
//    Hut m_hut;
//    Gather m_forest;
//    Gather m_clayPit;
//    Gather m_quarry;
//    Gather m_river;
//    Hunt m_hunt;
//    Toolshed m_toolMaker
//    Field m_field;
    int m_turn;
//    std::vector<Building> m_buildings;
};

#endif // BOARD_H
