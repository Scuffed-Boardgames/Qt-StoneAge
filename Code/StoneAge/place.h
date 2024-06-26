// Bernd Uijtdebroeks 2055267
#ifndef PLACE_H
#define PLACE_H

#include "player.h"

class Place : public QObject
{
    Q_OBJECT
public:
    Place();

    void resetWorkers(Colour colour); // Removes the workers of a given player
    virtual void addWorker(std::shared_ptr<Player>, int amount) = 0;
    int getWorkers(Colour colour);
    int totalWorkers();

    QJsonObject save();
    void load(const QJsonObject &json);

protected:
    int m_redWorkers;
    int m_blueWorkers;
    int m_yellowWorkers;
    int m_greenWorkers;

signals:
    void changedWorkers();
    void turnHappend();
};

#endif // PLACE_H
