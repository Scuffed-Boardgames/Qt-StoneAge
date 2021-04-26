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
