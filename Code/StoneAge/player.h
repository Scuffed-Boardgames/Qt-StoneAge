#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "worker.h"
#include "recourses.h"
class Player
{
public:
    Player();
    void addRecourse(Recourse recourse, int amount); // ads a given amount of a given recourse to the player(can be negative)
    void addWorker();// ads one worker to the players inventory
//    void addTool();
    int getRecourse(Recourse recourse); // gets the amount of a given recourse
    int getScore(); // gets the score the player curently has
    int getFoodGain(); // gets the amount of food gain the player curently has
    int getWorkerCount();// gets the amount of workers the player curently has
private:
    int m_foodCount;
    int m_woodCount;
    int m_clayCount;
    int m_stoneCount;
    int m_goldCount;

    int m_scoreCount;
    int m_foodGain;
    std::vector<Worker> m_workers;
};

#endif // PLAYER_H
