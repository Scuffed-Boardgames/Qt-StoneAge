// Denzell Mgbokwere 2054872
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

    void isUsed(); // Makes a tool used
    bool wasUsed(); // Returns if the tool is used
    void reset();
    QJsonObject save();


private:
    int m_level;
    bool m_used;
};

#endif // TOOL_H
