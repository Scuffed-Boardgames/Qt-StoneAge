// Bernd Uijtdebroeks 2055267
#include "board.h"
#include "payciv.h"
#include "payfood.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <random>

Board::Board() : m_ended{false}, m_currentPlayer{Colour::red}, m_hut(std::make_shared<Hut>()), m_forest{std::make_shared<Gather>(Resource::wood)},
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
    rerollBuildings();
    QFile file2(":/files/files/civilisation.json");
    file2.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray data2 = file2.readAll();
    file2.close();
    QJsonDocument document2 = QJsonDocument::fromJson(data2);
    QJsonObject jsonObject2 = document2.object();
    QJsonArray jsonCivs = jsonObject2["setBonus"].toArray();
    std::vector<std::shared_ptr<Civilisation>> civCards;
    for(int i = 0; i < jsonCivs.size(); ++i){
        civCards.push_back(std::make_shared<SetBonus>(jsonCivs[i].toObject()));
    }
    jsonCivs = jsonObject2["miscBonus"].toArray();
    for(int i = 0; i < jsonCivs.size(); ++i){
        civCards.push_back(std::make_shared<MiscBonus>(jsonCivs[i].toObject()));
    }
    jsonCivs = jsonObject2["cardBonus"].toArray();
    for(int i = 0; i < jsonCivs.size(); ++i){
        civCards.push_back(std::make_shared<CardBonus>(jsonCivs[i].toObject()));
    }
    jsonCivs = jsonObject2["diceBonus"].toArray();
    for(int i = 0; i < jsonCivs.size(); ++i){
        civCards.push_back(std::make_shared<DiceBonus>(jsonCivs[i].toObject()));
    }
    jsonCivs = jsonObject2["pickBonus"].toArray();
    for(int i = 0; i < jsonCivs.size(); ++i){
        civCards.push_back(std::make_shared<PickBonus>(jsonCivs[i].toObject()));
    }
    jsonCivs = jsonObject2["rollBonus"].toArray();
    for(int i = 0; i < jsonCivs.size(); ++i){
        civCards.push_back(std::make_shared<RollBonus>(jsonCivs[i].toObject()));
    }
    jsonCivs = jsonObject2["toolBonus"].toArray();
    for(int i = 0; i < jsonCivs.size(); ++i){
        civCards.push_back(std::make_shared<ToolBonus>(jsonCivs[i].toObject()));
    }
    while(civCards.size() > 0){
        int place = rand() % civCards.size();
        m_civilisationCards.push_back(civCards[place]);
        civCards.erase(civCards.begin() + place);
    }
    for(int i = 0; i < 4; ++i){
        m_openCivilisationCards.push_back(m_civilisationCards[i]);
        m_openCivilisationCards[i]->setCost(i + 1);
        m_civilisationCards.erase(m_civilisationCards.begin() + i);
    }
    newOpenCivCards();
}


void Board::feedWorkers(Colour colour){
    int foodNeeded = getPlayer(colour)->getWorkerCount();
    int ownedFood = getPlayer(colour)->getResource(Resource::food);
    if(foodNeeded <= ownedFood){
        getPlayer(colour)->addResource(Resource::food, -foodNeeded);
    }else{
        getPlayer(colour)->addResource(Resource::food, -ownedFood);
        foodNeeded -= ownedFood;
        PayFood* pay = new PayFood(getPlayer(colour), foodNeeded);
        pay->exec();
    }
}

void Board::resetWorkers(Colour colour){
    m_hunt->resetWorkers(colour);
    m_forest->resetWorkers(colour);
    m_clayPit->resetWorkers(colour);
    m_quarry->resetWorkers(colour);
    m_river->resetWorkers(colour);
    m_field->resetWorkers(colour);
    m_hut->resetWorkers(colour);
    m_toolShed->resetWorkers(colour);

    getPlayer(colour)->resetWorkers();

    emit m_hunt->changedWorkers();
    emit m_forest->changedWorkers();
    emit m_clayPit->changedWorkers();
    emit m_quarry->changedWorkers();
    emit m_river->changedWorkers();
    emit m_toolShed->changedWorkers();
    emit m_field->changedWorkers();
    emit m_hut->changedWorkers();
}


void Board::rerollBuildings(){
    std::vector<std::shared_ptr<Building>> buildings;
    for(int i = 0; i < 4; ++i){
        m_buildingCardStacks[i].back()->reset();
        buildings.insert(buildings.end(),m_buildingCardStacks[i].begin(), m_buildingCardStacks[i].end());
        m_buildingCardStacks[i].clear();
    }
    int i = 0;
    while(buildings.size() > 0){
        int place = rand() % buildings.size();
        m_buildingCardStacks[i].push_back(buildings[place]);
        buildings.erase(buildings.begin() + place);
        i = (++i) % 4;
    }
    for(int i = 0; i < 4; ++i){
        emit newBuild(m_buildingCardStacks[i].back(), i, m_buildingCardStacks[i].size());
    }
}

void Board::buildBuilding(Colour colour){
    for(int i = 0; i < 4; ++i){
        if(!m_buildingCardStacks[i].empty()){
            if(m_buildingCardStacks[i].back()->getStandingColour() == colour){
                std::shared_ptr<SetBuilding> setBuilding = std::dynamic_pointer_cast<SetBuilding>(m_buildingCardStacks[i].back());
                if(setBuilding){
                    SetBuildingPay buildingpay(getPlayer(colour), setBuilding);
                    buildingpay.exec();
                    if(buildingpay.getBought()){
                        newBuilding(i);
                    }
                } else{
                    std::shared_ptr<VarBuilding> varBuilding = std::dynamic_pointer_cast<VarBuilding>(m_buildingCardStacks[i].back());
                    VarBuildingPay buildingpay(getPlayer(colour), varBuilding);
                    buildingpay.exec();
                    if(buildingpay.getBought()){
                        newBuilding(i);
                    }
                }
            }
        }
    }

}

void Board::civilizeCivilisation(Colour colour){
    std::vector<std::shared_ptr<Civilisation>> list;
    for(int i = 0; i < (int)m_openCivilisationCards.size(); ++i){
        if(m_openCivilisationCards[i]->getStandingColour() == colour){
            std::shared_ptr<CardBonus> bonus = std::dynamic_pointer_cast<CardBonus>(m_openCivilisationCards[i]);
            if(bonus){
                bonus->setCard(m_civilisationCards.back());
                m_civilisationCards.pop_back();
            }
            std::shared_ptr<RollBonus> rollbonus = std::dynamic_pointer_cast<RollBonus>(m_openCivilisationCards[i]);

            PayCiv pay(getPlayer(colour), m_openCivilisationCards[i]);
            pay.exec();
            if(rollbonus && pay.getHasPayed()){
                std::shared_ptr<PickRolled> roll = std::make_shared<PickRolled>(nullptr, rollbonus->getDie(1), rollbonus->getDie(2), rollbonus->getDie(3), rollbonus->getDie(4));
                m_pickWindows.push_back(roll);
            }
            if(!pay.getHasPayed())
                list.push_back(m_openCivilisationCards[i]);
        }else{
            list.push_back(m_openCivilisationCards[i]);
        }
    }
    m_openCivilisationCards = list;

}
void Board::newOpenCivCards()
{
    for(int i = 0; i < 4; ++i){
        m_civilisationCards.push_back(m_openCivilisationCards.back());
        m_openCivilisationCards.pop_back();
    }
    std::shuffle(m_civilisationCards.begin(), m_civilisationCards.end(), std::default_random_engine(time(0)));
    for(int i = 0; i < 4; ++i){
        m_openCivilisationCards.push_back(m_civilisationCards[i]);
        m_civilisationCards.erase(m_civilisationCards.begin() + i);
    }
    for(size_t i = 0; i < m_openCivilisationCards.size(); ++i)
        m_openCivilisationCards[i]->setCost(i+1);
    emit newCiv(m_civilisationCards.size());
}

void Board::nextPlayer(int checked){
    if(checked == 4){
        m_currentPlayer = (Colour)((m_round) % 4);
        emit allWorkersPlaced();
    }else{
        m_currentPlayer = (Colour)(((int)m_currentPlayer + 1) % 4);
        if(getPlayer(m_currentPlayer)->getFreeWorkers() == 0){
            nextPlayer(checked + 1);
        }
    }
}

void Board::addRound(){
    m_round += 1;
    m_currentPlayer = (Colour)((m_round) % 4);
    emit roundChanged();
}

void Board::payResources(Colour colour){
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


std::shared_ptr<Building> Board::getOpenBuildingCard(int pos){
    return m_buildingCardStacks[pos].back();
}

void Board::end(){
    m_ended = true;
}

void Board::checkChosen(Colour colour)
{
    for(size_t i = 0; i < m_pickWindows.size(); ++i){
        if(!m_pickWindows[i]->hasChosen(colour)){
            m_pickWindows[i]->assignPlayer(m_players[(int)colour]);
            m_pickWindows[i]->exec();
        }
    }
}

int Board::newCivCards(){
    if(m_openCivilisationCards.size() < 4 && m_civilisationCards.size() == 0){
        m_ended = true;
        return 0;
    }
    while(m_openCivilisationCards.size() < 4){
        m_openCivilisationCards.push_back(m_civilisationCards.back());
        m_civilisationCards.pop_back();
    }
    for(size_t i = 0; i < m_openCivilisationCards.size(); ++i)
        m_openCivilisationCards[i]->setCost(i+1);
    return m_civilisationCards.size();

}
std::shared_ptr<Civilisation> Board::getOpenCivilisationCard(int pos) const
{
    return m_openCivilisationCards[pos];
}


void Board::newBuilding(int place){
    if(!m_buildingCardStacks[place].empty()){
        m_buildingCardStacks[place].pop_back();
    }
    if(m_buildingCardStacks[place].empty()){
        emit newBuild(nullptr, place, 0);
        return;
    }
    emit newBuild(m_buildingCardStacks[place].back(), place, m_buildingCardStacks[place].size());
}

bool Board::checkStacks(){
    for(std::vector<std::shared_ptr<Building>> buildingStack : m_buildingCardStacks){
        if(buildingStack.empty())
            return true;
    }
    return false;
}

Colour Board::getCurrentPlayer() const{
    return m_currentPlayer;
}

int Board::getRound() const{
    return m_round;
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

std::shared_ptr<ToolShed> Board::getToolShed(){
    return m_toolShed;
}

std::shared_ptr<Hut> Board::getHut(){
    return m_hut;
}

std::shared_ptr<Field> Board::getField(){
    return m_field;
}


void Board::load(const QJsonObject &json){
    m_ended = json["ended"].toBool();
    m_round = json["round"].toInt();
    m_currentPlayer = (Colour)json["activePlayer"].toDouble();
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
        emit newBuild(m_buildingCardStacks[i].back(), i, m_buildingCardStacks[i].size());
    }

    QJsonArray civCards = json["civs"].toArray();
    m_civilisationCards.clear();
    for(int i = 0; i < civCards.size(); ++i){
        if(civCards[i].toObject().contains("resource")){
            m_civilisationCards.push_back(std::make_shared<SetBonus>(civCards[i].toObject()));
        }else if(civCards[i].toObject().contains("score")){
            m_civilisationCards.push_back(std::make_shared<MiscBonus>(civCards[i].toObject()));
        }else if(civCards[i].toObject().contains("tools")){
            m_civilisationCards.push_back(std::make_shared<ToolBonus>(civCards[i].toObject()));
        }else if(civCards[i].toObject().contains("diceResource")){
            m_civilisationCards.push_back(std::make_shared<DiceBonus>(civCards[i].toObject()));
        }else if(civCards[i].toObject().contains("hasCard")){
            m_civilisationCards.push_back(std::make_shared<CardBonus>(civCards[i].toObject()));
        }else if(civCards[i].toObject().contains("choice")){
            m_civilisationCards.push_back(std::make_shared<PickBonus>(civCards[i].toObject()));
        }else if(civCards[i].toObject().contains("die1")){
            m_civilisationCards.push_back(std::make_shared<RollBonus>(civCards[i].toObject()));
        }
    }
    QJsonArray openCivCards = json["openCivs"].toArray();
    m_openCivilisationCards.clear();
    for(int i = 0; i < openCivCards.size(); ++i){
        if(openCivCards[i].toObject().contains("resource")){
            m_openCivilisationCards.push_back(std::make_shared<SetBonus>(openCivCards[i].toObject()));
        }else if(openCivCards[i].toObject().contains("score")){
            m_openCivilisationCards.push_back(std::make_shared<MiscBonus>(openCivCards[i].toObject()));
        }else if(openCivCards[i].toObject().contains("tools")){
            m_openCivilisationCards.push_back(std::make_shared<ToolBonus>(openCivCards[i].toObject()));
        }else if(openCivCards[i].toObject().contains("diceResource")){
            m_openCivilisationCards.push_back(std::make_shared<DiceBonus>(openCivCards[i].toObject()));
        }else if(openCivCards[i].toObject().contains("hasCard")){
            m_openCivilisationCards.push_back(std::make_shared<CardBonus>(openCivCards[i].toObject()));
        }else if(openCivCards[i].toObject().contains("choice")){
            m_openCivilisationCards.push_back(std::make_shared<PickBonus>(openCivCards[i].toObject()));
        }else if(openCivCards[i].toObject().contains("die1")){
            m_openCivilisationCards.push_back(std::make_shared<RollBonus>(openCivCards[i].toObject()));
        }
    }
    emit newCiv(m_civilisationCards.size());
    QJsonArray pickWindows = json["pickWindows"].toArray();
    m_pickWindows.clear();
    for(int i = 0; i < pickWindows.size(); ++i){
        m_pickWindows.push_back(std::make_shared<PickRolled>(pickWindows[i].toObject()));
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
    QJsonArray civCards;
    for(int i = 0; i < (int)m_civilisationCards.size(); ++i){
        civCards.append(m_civilisationCards[i]->save());
    }
    QJsonArray openCivCards;
    for(int i = 0; i < (int)m_openCivilisationCards.size(); ++i){
        openCivCards.append(m_openCivilisationCards[i]->save());
    }
    QJsonArray pickWindows;
    for(int i = 0; i < (int)m_pickWindows.size(); ++i){
        pickWindows.append(m_pickWindows[i]->save());
    }
    QJsonObject hut = m_hut->save();
    QJsonObject forest = m_forest->save();
    QJsonObject clayPit = m_clayPit->save();
    QJsonObject quarry = m_quarry->save();
    QJsonObject river = m_river->save();
    QJsonObject hunt = m_hunt->save();
    QJsonObject toolShed = m_toolShed->save();
    QJsonObject field = m_field->save();
    QJsonObject json = {{"ended", m_ended},
                        {"round", m_round},
                        {"activePlayer", (int)m_currentPlayer},
                        {"players", players},
                        {"hut", hut},
                        {"forest", forest},
                        {"clayPit", clayPit},
                        {"quarry", quarry},
                        {"river", river},
                        {"hunt", hunt},
                        {"toolShed", toolShed},
                        {"field", field},
                        {"buildings", buildingsStacks},
                        {"civs", civCards},
                        {"openCivs", openCivCards},
                        {"pickWindows", pickWindows}};
    return json;
}

bool Board::getEnded() const
{
    return m_ended;
}
