#ifndef PICKROLLED_H
#define PICKROLLED_H

#include <QDialog>
#include "player.h"

namespace Ui {
class PickRolled;
}

class PickRolled : public QDialog
{
    Q_OBJECT

public:
    explicit PickRolled(std::shared_ptr<Player> player = nullptr, int die1 = 0, int die2 = 0, int die3 = 0, int die4 = 0, QWidget *parent = nullptr);
    ~PickRolled();

private slots:
    void on_okayButton_clicked();

private:
    Ui::PickRolled *ui;
    std::shared_ptr<Player> m_player;
    void giveResource(QString resource);
    void assignResources();
    void assignDice(int die1, int die2, int die3, int die4);
    void assignPlayer(std::shared_ptr<Player> player);
    int m_resources[4];
};

#endif // PICKROLLED_H
