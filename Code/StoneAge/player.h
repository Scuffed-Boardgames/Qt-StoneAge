// Denzell Mgbokwere 2054872
#ifndef PLAYER_H
#define PLAYER_H

#include "resources.h"
#include "colour.h"
#include "tool.h"
#include "civbonuses.h"

class Player : public QObject
{
    Q_OBJECT

public:
    Player();
    Player(Colour colour);

    void addResource(Resource resource, int amount); // ads a given amount of a given resource to the player(can be negative)
    void addWorker();// ads one worker to the players inventory
    void addTool();
    void addScore(int amount);
    void addFoodGain();
    void addBuilding();
    void addExtraTool(int tool);
    void addBonus(int farmers, int makers, int builders, int shamen, CivBonus bonus);

    int getResource(Resource resource); // gets the amount of a given resource
    int getScore(); // gets the score the player curently has
    int getFoodGain(); // gets the amount of food gain the player curently has
    int getWorkerCount();// gets the amount of workers the player curently has
    int getFreeWorkers();// gets the amount of free workers the player curently has
    Colour getColour() const;
    Tool* getTools();
    QString getString();

    bool maxToolsReached();
    void deleteExtraTool(int tool);

    void resetTools();
    void resetWorkers();

    void setWorkersOccupied(int amount);
    void disableTool(int nr);

    QJsonObject save();
    void load(const QJsonObject &json);

    int calcScore();
    int calcTieBreak();

    int getLowestToolLevel();
    int getBuildingCount() const;

    std::vector<int> getExtraTools() const;

signals:
    void dataChanged();

private:
    int m_foodCount; //saved & loaded
    int m_woodCount; //saved & loaded
    int m_clayCount; //saved & loaded
    int m_stoneCount; //saved & loaded
    int m_goldCount; //saved & loaded
    int m_buildingCount; //saved  & loaded
    int m_scoreCount; //saved & loaded
    int m_foodGain; //saved & loaded
    Colour m_colour; //saved & loaded
    int m_freeWorkers; //saved & loaded
    int m_workers; //saved & loaded
    Tool m_tools[3]; //saved & loaded
    std::vector<int> m_extraTools; //saved & loaded
    int m_civBonuses[8]; //saved & loaded5
    int m_farmerCount; //saved & loaded
    int m_toolMakerCount; //saved & loaded
    int m_hutBuilderCount; //saved & loaded
    int m_shamanCount; //saved & loaded
};

#endif // PLAYER_H
