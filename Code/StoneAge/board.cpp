#include "board.h"

Board::Board() : m_forest{Resource::wood}, m_clayPit{Resource::clay}, m_quarry{Resource::stone}, m_river{Resource::gold}, m_hunt{Resource::food}
{
    m_turn = 0;
    for(int i = 0; i < 4; ++i){
        Player test((Colour)i);
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

Gather* Board::getGather(Resource resource)
{
    switch(resource){
    case(Resource::food):
        return &m_hunt;
    case(Resource::wood):
        return &m_forest;
    case(Resource::clay):
        return &m_clayPit;
    case(Resource::stone):
        return &m_quarry;
    case(Resource::gold):
        return &m_river;
    default:
        return nullptr;
    }
}
