#ifndef WORKER_H
#define WORKER_H

class Worker
{
public:
    Worker(void* owner);
    bool isOccupied();
    void setOccupied();
    void reset();
private:
    void* m_owner;
    bool m_occupied;
};

#endif // WORKER_H
