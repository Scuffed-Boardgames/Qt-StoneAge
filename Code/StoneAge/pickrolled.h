// Bernd Uijtdebroeks 2055267
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
    PickRolled(const QJsonObject &json);
    ~PickRolled();
     QJsonObject save();
     bool hasChosen(Colour colour);
     void assignPlayer(std::shared_ptr<Player> player);

private slots:
    void on_okayButton_clicked();

private:
    Ui::PickRolled *ui;
    std::shared_ptr<Player> m_player;
    int m_resources[4];
    bool m_chosen[4];

    void giveResource(QString resource);
    void assignResources();
};

#endif // PICKROLLED_H
