#ifndef TOOL_H
#define TOOL_H

#include <QJsonObject>

class Tool
{
public:
    Tool();
    Tool(const QJsonObject &tool);

    int getLevel();
    void levelUp();

    void isUsed();
    bool wasUsed();
    void reset();
    QJsonObject save();


private:
    int m_level;
    bool m_used;
};

#endif // TOOL_H
