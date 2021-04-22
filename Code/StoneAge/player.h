#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "worker.h"
#include "recourses.h"
class Player
{
public:
    Player();
    void addRecourse(Recourse recourse, int amount);
    void addWorker();
//    void addTool();
    int getRecourse(Recourse recourse);
    int getScore();
    int getFoodGain();
    int getWorkerCount();
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
