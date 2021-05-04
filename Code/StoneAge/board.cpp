#include "board.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>

Board::Board() : m_currentPlayer{Colour::red}, m_hut(std::make_shared<Hut>()), m_forest{std::make_shared<Gather>(Resource::wood)},
    m_clayPit{std::make_shared<Gather>(Resource::clay)}, m_quarry{std::make_shared<Gather>(Resource::stone)}, m_river{std::make_shared<Gather>(Resource::gold)},
    m_hunt{std::make_shared<Gather>(Resource::food)}, m_toolShed(std::make_shared<ToolShed>()), m_field(std::make_shared<Field>())
{
    m_round = 0;
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
    std::vector<std::shared_ptr<Building>> buildingCards;
    for(int i = 0; i < jsonBuildings.size(); ++i){
        buildingCards.push_back(std::make_shared<SetBuilding>(jsonBuildings[i].toObject()));
    }
    jsonBuildings = jsonObject["varBuildings"].toArray();
    for(int i = 0; i < jsonBuildings.size(); ++i){
        buildingCards.push_back(std::make_shared<VarBuilding>(jsonBuildings[i].toObject()));
    }
    int i = 0;
    while(buildingCards.size() > 0){
        int place = rand() % buildingCards.size();
        m_buildingCardStacks[i].push_back(buildingCards[place]);
        buildingCards.erase(buildingCards.begin() + place);
        i = (++i) % 4;

    }
}

void Board::newBuilding(int place){
    m_buildingCardStacks[place].pop_back();
    if(m_buildingCardStacks[place].size() == 0){
        return;
    }
    emit newBuild(m_buildingCardStacks[place].back(), place);
}

void Board::rerollBuildings(){
    std::vector<std::shared_ptr<Building>> buildings;
    for(int i = 0; i < 4; ++i){
        m_buildingCardStacks[i].back()->reset();
        buildings.insert(buildings.end(),m_buildingCardStacks[i].begin(), m_buildingCardStacks[i].end());
    }
    int i = 0;
    while(buildings.size() > 0){
        int place = rand() % buildings.size();
        m_buildingCardStacks[i].push_back(buildings[place]);
        buildings.erase(buildings.begin() + place);
        i = (++i) % 4;
    }
    for(int i = 0; i < 4; ++i){
        emit newBuild(m_buildingCardStacks[i].back(), i);
    }
//        int place = rand() % m_buildingCardStacks[i].size();
//        std::shared_ptr<Building> tmp = m_buildingCardStacks[i].back();
//        m_buildingCardStacks[i].back() = m_buildingCardStacks[i][place];
//        m_buildingCardStacks[i][place] = tmp;
//        ;
}

Colour Board::getCurrentPlayer() const
{
    return m_currentPlayer;
}

void Board::nextPlayer(int checked)
{
    if(checked == 4){
        m_currentPlayer = Colour::red;
        emit allWorkersPlaced();
    }else{
        m_currentPlayer = (Colour)(((int)m_currentPlayer + 1)%4);
        if(getPlayer(m_currentPlayer)->getFreeWorkers() == 0){
            nextPlayer(checked + 1);
        }
    }
}

void Board::feedWorkers()
{
    for(int i = 0; i < 4; ++i){
        int foodNeeded = m_players[i]->getWorkerCount();
        int ownedFood = m_players[i]->getResource(Resource::food);
        if(foodNeeded <= ownedFood){
            m_players[i]->addResource(Resource::food, -foodNeeded);
        }else{
            m_players[i]->addResource(Resource::food, -ownedFood);
            foodNeeded -= ownedFood;
        }
        if(foodNeeded > 0){
            m_players[i]->addScore(-10);
        }
    }
}

int Board::getRound() const
{
    return m_round;
}

void Board::addRound()
{
    m_round += 1;
    roundChanged();
}

std::shared_ptr<Building> Board::getOpenBuildingCard(int pos){
    return m_buildingCardStacks[pos].back();
}

void Board::setUpGame()
{

}

void Board::payResources(Colour colour)
{
    int playerInt = (int)colour;

    if(m_hunt->getWorkers(colour) != 0){
        m_hunt->giveResource(m_players[playerInt]);
    }
    if(m_forest->getWorkers(colour) != 0){
        m_forest->giveResource(m_players[playerInt]);
    }
    if(m_clayPit->getWorkers(colour) != 0){
        m_clayPit->giveResource(m_players[playerInt]);
    }
    if(m_quarry->getWorkers(colour) != 0){
        m_quarry->giveResource(m_players[playerInt]);
    }
    if(m_river->getWorkers(colour) != 0){
        m_river->giveResource(m_players[playerInt]);
    }
    if(m_field->getWorkers(colour) != 0){
        m_field->giveResource(m_players[playerInt]);
    }
    if(m_hut->getWorkers(colour) != 0){
        m_hut->giveResource(m_players[playerInt]);
    }
    if(m_toolShed->getWorkers(colour) != 0){
        m_toolShed->giveResource(m_players[playerInt]);
    }
    m_players[playerInt]->addResource(Resource::food, m_players[playerInt]->getFoodGain());
}

std::shared_ptr<Player> Board::getPlayer(Colour colour){
    return m_players[(int)colour];
}

std::shared_ptr<Gather> Board::getGather(Resource resource)
{
    switch(resource){
    case(Resource::food):
        return m_hunt;
    case(Resource::wood):
        return m_forest;
    case(Resource::clay):
        return m_clayPit;
    case(Resource::stone):
        return m_quarry;
    case(Resource::gold):
        return m_river;
    default:
        return nullptr;
    }
}

void Board::resetWorkers()
{
    m_hunt->resetWorkers();
    m_forest->resetWorkers();
    m_clayPit->resetWorkers();
    m_quarry->resetWorkers();
    m_river->resetWorkers();
    m_field->resetWorkers();
    m_hut->resetWorkers();
    m_toolShed->resetWorkers();
    for (int i = 0; i<4 ; ++i){
        m_players[i]->resetWorkers();
        m_players[i]->resetTools();
    }
    emit m_hunt->changedWorkers();
    emit m_forest->changedWorkers();
    emit m_clayPit->changedWorkers();
    emit m_quarry->changedWorkers();
    emit m_river->changedWorkers();
    emit m_toolShed->changedWorkers();
    emit m_field->changedWorkers();
    emit m_hut->changedWorkers();
}

std::shared_ptr<ToolShed> Board::getToolShed(){
    return m_toolShed;
}

std::shared_ptr<Hut> Board::getHut()
{
    return m_hut;
}

std::shared_ptr<Field> Board::getField()
{
    return m_field;
}

void Board::load(const QJsonObject &json){
    m_round = (int)json["round"].toDouble();
    QJsonArray players = json["players"].toArray();
    for(int i = 0; i < 4; ++i){
        m_players[i]->load(players[i].toObject());
    }
    QJsonArray buildingsStacks = json["buildings"].toArray();
    for(int i = 0; i < 4; ++i){
        m_buildingCardStacks[i].clear();
        QJsonArray buildings = buildingsStacks[i].toArray();
        for(int j = 0; j < buildings.size(); ++j){
            if(buildings[j].toObject().contains("diffMaterials")){
                m_buildingCardStacks[i].push_back(std::make_shared<VarBuilding>(buildings[j].toObject()));
            } else{
                m_buildingCardStacks[i].push_back(std::make_shared<SetBuilding>(buildings[j].toObject()));
            }

        }

    }
    m_hut->load(json["hut"].toObject());
    m_forest->load(json["forest"].toObject());
    m_clayPit->load(json["clayPit"].toObject());
    m_quarry->load(json["quarry"].toObject());
    m_river->load(json["river"].toObject());
    m_hunt->load(json["hunt"].toObject());
    m_toolShed->load(json["toolShed"].toObject());
    m_field->load(json["field"].toObject());
}

QJsonObject Board::save(){
    QJsonArray players;
    for(int i = 0; i < 4; ++i){
        players.append(m_players[i]->save());
    }
    QJsonArray buildingsStacks;
    for(int i = 0; i < 4; ++i){
        QJsonArray buildings;
        for(int j = 0; j < (int)m_buildingCardStacks[i].size(); ++j){
            buildings.append(m_buildingCardStacks[i][j]->save());
        }
        buildingsStacks.append(buildings);
    }

    QJsonObject hut = m_hut->save();
    QJsonObject forest = m_forest->save();
    QJsonObject clayPit = m_clayPit->save();
    QJsonObject quarry = m_quarry->save();
    QJsonObject river = m_river->save();
    QJsonObject hunt = m_hunt->save();
    QJsonObject toolShed = m_toolShed->save();
    QJsonObject field = m_field->save();
    QJsonObject json = {{"round", m_round},
                        {"players", players},
                        {"hut", hut},
                        {"forest", forest},
                        {"clayPit", clayPit},
                        {"quarry", quarry},
                        {"river", river},
                        {"hunt", hunt},
                        {"toolShed", toolShed},
                        {"field", field},
                        {"buildings", buildingsStacks}};
    return json;
}
