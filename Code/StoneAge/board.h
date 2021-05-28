// Bernd Uijtdebroeks 2055267
#ifndef BOARD_H
#define BOARD_H

#include "player.h"
#include "hut.h"
#include "gather.h"
#include "toolshed.h"
#include "field.h"
#include "varbuildingpay.h"
#include "setbuildingpay.h"
#include "setbuilding.h"
#include "varbuilding.h"
#include "cardbonus.h"
#include "dicebonus.h"
#include "miscbonus.h"
#include "pickbonus.h"
#include "rollbonus.h"
#include "setbonus.h"
#include "toolbonus.h"
#include "pickrolled.h"

class Board : public QObject
{
    Q_OBJECT
public:
    Board();

    void resetWorkers(Colour colour); // Resets all workers everywhere for a specific player
    void feedWorkers(Colour colour); // Process the feeding of workers according to the rules

    std::shared_ptr<Building> getOpenBuildingCard(int pos); // Returns the top card of the chosen pile
    void rerollBuildings(); // Shuffles the building cards
    void buildBuilding(Colour colour); // Processes the buying of a building

    void newOpenCivCards(); // Shuffles the civilisation cards and draws new open ones

    void nextPlayer(int checked = 0); // Calculates the next player
    void payResources(Colour colour); // Processes all the workers placed on resources for a specific player
    void addRound(); // Ups the round counter

    std::shared_ptr<ToolShed> getToolShed();
    std::shared_ptr<Hut> getHut();
    std::shared_ptr<Field> getField();
    std::shared_ptr<Player> getPlayer(Colour colour);
    std::shared_ptr<Gather> getGather(Resource resource);
    int getRound() const;
    Colour getCurrentPlayer() const;

    void load(const QJsonObject &json);
    QJsonObject save();

    bool getEnded() const;

    bool checkStacks(); // Checks if one of the buildingstacks is empty
    void end(); // Sets the ended bool to true
    void checkChosen(Colour colour); // Checks and processes choices (for the choice civ cards) of a specific player
    std::shared_ptr<Civilisation> getOpenCivilisationCard(int pos) const; // Returns the civilisation card on the chosen position

    void civilizeCivilisation(Colour colour); // Processes the buying of a civilisation card
    int newCivCards(); // Updates the civilisation cards on the gameboard

signals:
    void newBuild(std::shared_ptr<Building> building, int pos, int stackSize);
    void allWorkersPlaced();
    void workersReset();
    void roundChanged();
    void newCiv(int stackSize);

private:
    void newBuilding(int place);

    bool m_ended; //saved & loaded
    Colour m_currentPlayer; //saved & loaded
    std::vector<std::shared_ptr<Building>> m_buildingCardStacks[4]; //saved & loaded
    std::vector<std::shared_ptr<Civilisation>> m_civilisationCards; //saved & loaded
    std::vector<std::shared_ptr<Civilisation>> m_openCivilisationCards; //saved & loaded
    std::shared_ptr<Player> m_players[4]; //saved & loaded
    std::shared_ptr<Hut> m_hut; //saved & loaded
    std::shared_ptr<Gather> m_forest; //saved & loaded
    std::shared_ptr<Gather> m_clayPit; //saved & loaded
    std::shared_ptr<Gather> m_quarry; //saved & loaded
    std::shared_ptr<Gather> m_river; //saved & loaded
    std::shared_ptr<Gather> m_hunt; //saved & loaded
    std::shared_ptr<ToolShed> m_toolShed; //saved & loaded
    std::shared_ptr<Field> m_field; //saved & loaded
    int m_round; //saved & loaded
    std::vector<std::shared_ptr<PickRolled>> m_pickWindows; // needs to be saved and loaded

};

#endif // BOARD_H
