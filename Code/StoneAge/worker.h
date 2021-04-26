#ifndef WORKER_H
#define WORKER_H

class Worker
{
public:
    Worker(void* owner);
    void* getOccupation();
    void setOccupation(void *occupation);
    void setOccupation();
private:
    void* m_owner;
    void* m_occupation;
};

#endif // WORKER_H
