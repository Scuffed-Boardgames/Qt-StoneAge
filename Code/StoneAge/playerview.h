#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H
#include <QGraphicsScene>
#include "player.h"

class PlayerView : public QGraphicsScene
{
public:
    PlayerView(QColor color, std::shared_ptr<Player> player, QObject* parent = nullptr); // constructor of player

    void highlight();
    void unHighlight();
    int showScore();
    int showTieBreak();
    void unEnd();
public slots:
    void updateText(); // updates player text

private:
    std::shared_ptr<Player> m_player;
    std::vector<QGraphicsTextItem*> m_recources;

};

#endif // PLAYERVIEW_H
