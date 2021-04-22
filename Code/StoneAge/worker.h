#ifndef WORKER_H
#define WORKER_H
#include <memory>

class Worker
{
public:
    Worker(void* owner);
private:
    void* m_owner;
//    Place* m_occupation;
};

#endif // WORKER_H
