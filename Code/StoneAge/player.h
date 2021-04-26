#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "worker.h"
#include "resources.h"
#include "colour.h"

class Player
{
public:
    Player();
    Player(Colour colour);
    void addResource(Resource resource, int amount); // ads a given amount of a given resource to the player(can be negative)
    void addWorker();// ads one worker to the players inventory
//    void addTool();
    int getResource(Resource resource); // gets the amount of a given resource
    int getScore(); // gets the score the player curently has
    int getFoodGain(); // gets the amount of food gain the player curently has
    int getWorkerCount();// gets the amount of workers the player curently has
    int getAmountFreeWorkers();
    std::vector<Worker*> getFreeWorkers();
    Colour getColour() const;
    void resetWorkers();

private:
    int m_foodCount;
    int m_woodCount;
    int m_clayCount;
    int m_stoneCount;
    int m_goldCount;

    int m_scoreCount;
    int m_foodGain;
    Colour m_colour;
    std::vector<Worker> m_workers;
};

#endif // PLAYER_H
