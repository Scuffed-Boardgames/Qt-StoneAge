#include "place.h"

Place::Place() : QObject(nullptr), m_redWorkers{0}, m_blueWorkers{0}, m_yellowWorkers{0}, m_greenWorkers{0}
{
}

void Place::resetWorkers()
{
    m_redWorkers = 0;
    m_blueWorkers = 0;
    m_yellowWorkers = 0;
    m_greenWorkers = 0;
}

int Place::getWorkers(Colour colour)
{
    switch (colour) {
    case Colour::red:
        return m_redWorkers;
    case Colour::blue:
        return m_blueWorkers;
    case Colour::yellow:
        return m_yellowWorkers;
    case Colour::green:
        return m_greenWorkers;
    default:
        return -1;
    }
}

QJsonObject Place::save(){
    QJsonObject json = {{"redWorkers", m_redWorkers},
                        {"blueWorkers", m_blueWorkers},
                        {"yellowWorkers", m_yellowWorkers},
                        {"greenWorkers", m_greenWorkers}};
    return json;
}

void Place::load(const QJsonObject &json){
    m_redWorkers = (int)json["redWorkers"].toDouble();
    m_blueWorkers = (int)json["blueWorkers"].toDouble();
    m_yellowWorkers = (int)json["yellowWorkers"].toDouble();
    m_greenWorkers = (int)json["greenWorkers"].toDouble();
    emit changedWorkers();
}
