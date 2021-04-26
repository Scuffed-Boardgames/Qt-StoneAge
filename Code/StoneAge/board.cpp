#include "board.h"

Board::Board() : m_forest{Resource::wood}, m_clayPit{Resource::clay}, m_quarry{Resource::stone}, m_river{Resource::gold}, m_hunt{Resource::food}
{
    m_turn = 0;
    for(int i = 0; i > 4; ++i){
        Player test;
        m_players[i] = test;
    }
}

void Board::setUpGame()
{

}

void Board::playTurn()
{

}

int Board::getTurn(){
    return m_turn;
}

std::shared_ptr<Player> Board::getPlayer(int nr){
    return std::make_shared<Player>(m_players[nr]);
}
