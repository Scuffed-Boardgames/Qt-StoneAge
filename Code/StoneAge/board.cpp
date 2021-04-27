#include "board.h"

Board::Board() : m_forest{Resource::wood}, m_clayPit{Resource::clay}, m_quarry{Resource::stone}, m_river{Resource::gold}, m_hunt{Resource::food}, m_toolShed()
{
    m_turn = 0;
    for(int i = 0; i < 4; ++i){
        m_players[i] = std::make_shared<Player>((Colour)i);
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

std::shared_ptr<Player> Board::getPlayer(Colour colour){
    return m_players[(int)colour];
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

void Board::resetWorkers()
{
    m_hunt.resetWorkers();
    m_forest.resetWorkers();
    m_clayPit.resetWorkers();
    m_quarry.resetWorkers();
    m_river.resetWorkers();
    m_field.resetWorkers();
    m_hut.resetWorkers();
    m_toolShed.resetWorkers();
    for (int i = 0; i<4 ; ++i){
        m_players[i].reset();
    }
}

ToolShed* Board::getToolShed(){
    return &m_toolShed;
}
