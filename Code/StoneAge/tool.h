#ifndef TOOL_H
#define TOOL_H


class Tool
{
public:
    Tool();
    int getLevel();
    void levelUp();
    void isUsed();
    bool wasUsed();
    void reset();
private:
    int m_level;
    bool m_used;
};

#endif // TOOL_H
