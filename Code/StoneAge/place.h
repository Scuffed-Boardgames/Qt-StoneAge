#ifndef PLACE_H
#define PLACE_H

#include "player.h"
#include <memory>
#include <QObject>

class Place : public QObject
{
    Q_OBJECT
public:
    Place();
    void resetWorkers();
    void resetWorkers(Colour colour);
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
    void resourcesChanged();
    void turnHappend();
};

#endif // PLACE_H
