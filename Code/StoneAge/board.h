#ifndef BOARD_H
#define BOARD_H

#include "player.h"

class Board
{
public:
    Board();
    void setUpGame();
    void playTurn();
    int getTurn();
private:
    //Player[4] m_players;
    //Hut m_hut;
    //Gather m_forest;
    //Gather m_clayPit;
    //Gather m_quarry;
    //Gather m_river;
    //Hunt m_hunt;
    //Toolshed m_toolMaker
    //Field m_field;
    int m_turn;
    //std::vector<Building> m_buildings;
};

#endif // BOARD_H
