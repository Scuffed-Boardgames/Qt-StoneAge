// Bernd Uijtdebroeks 2055267
#ifndef TOOLBONUS_H
#define TOOLBONUS_H

#include "civilisation.h"

class ToolBonus : public Civilisation
{
    Q_OBJECT
public:
    ToolBonus(Colour colour, int farmers, int makers, int builders, int shamen, CivBonus bonus, int cost, int tool);
    ToolBonus(const QJsonObject &json);
    QJsonObject save();

    void giveItems(std::shared_ptr<Player> player);

    int getTool() const;

private:
    int m_tool;
};

#endif // TOOLBONUS_H
