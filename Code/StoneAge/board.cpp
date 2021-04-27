#include "board.h"
#include <QJsonArray>

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

void Board::load(const QJsonObject &json){
//    if(json.contains("turn") && json["turn"].isDouble()){
        m_turn = (int)json["turn"].toDouble();

//    }
//    if(json.contains("players") && json["players"].isArray()){
        QJsonArray players = json["players"].toArray();
        for(int i = 0; i < 4; ++i){
            m_players[i]->load(players[i].toObject());
            emit m_players[i]->dataChanged();
        }

//    }
//    if(json.contains("hut") && json["hut"].isObject()){
        m_hut.load(json["hut"].toObject());

//    }
//    if(json.contains("forest") && json["forest"].isObject()){
        m_forest.load(json["forest"].toObject());

//    }
//    if(json.contains("clayPit") && json["clayPit"].isObject()){
        m_clayPit.load(json["clayPit"].toObject());

//    }
//    if(json.contains("quarry") && json["quarry"].isObject()){
        m_quarry.load(json["quarry"].toObject());

//    }
//    if(json.contains("river") && json["river"].isObject()){
        m_river.load(json["river"].toObject());

//    }
//    if(json.contains("hunt") && json["hunt"].isObject()){
        m_hunt.load(json["hunt"].toObject());

//    }
//    if(json.contains("toolShes") && json["toolShed"].isObject()){
        m_toolShed.load(json["toolShed"].toObject());

//    }
//    if(json.contains("field") && json["field"].isObject()){
        m_field.load(json["field"].toObject());
//    }
}

QJsonObject Board::save(){
    QJsonArray players;
    for(int i = 0; i < 4; ++i){
        players.append(m_players[i]->save());
    }
    QJsonObject hut = m_hut.save();
    QJsonObject forest = m_forest.save();
    QJsonObject clayPit = m_clayPit.save();
    QJsonObject quarry = m_quarry.save();
    QJsonObject river = m_river.save();
    QJsonObject hunt = m_hunt.save();
    QJsonObject toolShed = m_toolShed.save();
    QJsonObject field = m_field.save();
    QJsonObject json = {{"turn", m_turn},
                        {"players", players},
                        {"hut", hut},
                        {"forest", forest},
                        {"clayPit", clayPit},
                        {"quarry", quarry},
                        {"river", river},
                        {"hunt", hunt},
                        {"toolShed", toolShed},
                        {"field", field}};
    return json;
}
