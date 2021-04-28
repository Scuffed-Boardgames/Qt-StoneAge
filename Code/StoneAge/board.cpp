#include "board.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>

Board::Board() : m_forest{Resource::wood}, m_clayPit{Resource::clay}, m_quarry{Resource::stone}, m_river{Resource::gold}, m_hunt{Resource::food}, m_toolShed()
{
    m_turn = 0;
    for(int i = 0; i < 4; ++i){
        m_players[i] = std::make_shared<Player>((Colour)i);
    }

    QFile file(":/files/files/buildings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray data = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonObject jsonObject = document.object();
    QJsonArray jsonBuildings = jsonObject["setBuildings"].toArray();
    for(int i = 0; i < jsonBuildings.size(); ++i){
        m_buildingCards.push_back(std::make_shared<SetBuilding>(jsonBuildings[i].toObject()));
    }
    for(int i = 0; i < 4; ++i){
        int place = rand() % m_buildingCards.size();
        m_openBuildingCards[i] = m_buildingCards[place];
        m_buildingCards.erase(m_buildingCards.begin() + place);
    }
}

void Board::newBuilding(int place){
    if(m_buildingCards.size() == 0){
        return;
    }
    int randplace = rand() % m_buildingCards.size();
    m_openBuildingCards[place] = m_buildingCards[randplace];
    m_buildingCards.erase(m_buildingCards.begin() + randplace);
    emit newBuild(m_openBuildingCards[place], place);
}

void Board::rerollBuildings(){
    if(m_buildingCards.size() == 0){
        return;
    }
    for(int i = 0; i < 4; ++i){
        m_openBuildingCards[i]->reset();
        m_buildingCards.push_back(m_openBuildingCards[i]);
    }
    for(int i = 0; i < 4; ++i){
        int place = rand() % m_buildingCards.size();
        m_openBuildingCards[i] = m_buildingCards[place];
        m_buildingCards.erase(m_buildingCards.begin() + place);
        emit newBuild(m_openBuildingCards[i], i);
    }
}

std::shared_ptr<Building> Board::getOpenBuildingCard(int pos){
    return m_openBuildingCards[pos];
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
    m_turn = (int)json["turn"].toDouble();
    QJsonArray players = json["players"].toArray();
    for(int i = 0; i < 4; ++i){
        m_players[i]->load(players[i].toObject());
    }

    m_hut.load(json["hut"].toObject());
    m_forest.load(json["forest"].toObject());
    m_clayPit.load(json["clayPit"].toObject());
    m_quarry.load(json["quarry"].toObject());
    m_river.load(json["river"].toObject());
    m_hunt.load(json["hunt"].toObject());
    m_toolShed.load(json["toolShed"].toObject());
    m_field.load(json["field"].toObject());
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
