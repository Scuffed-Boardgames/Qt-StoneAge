#ifndef PAYFOOD_H
#define PAYFOOD_H

#include <QDialog>
#include "player.h"

namespace Ui {
class PayFood;
}
class PayFood : public QDialog
{
    Q_OBJECT
public:
    PayFood(std::shared_ptr<Player> player, int amount);
    ~PayFood();

private slots:
    void editText();
    void on_acceptButton_clicked();
    void on_scoreButton_clicked();

private:
    int totalSet();
    void removeResources();
    std::shared_ptr<Player> m_player;
    int m_amount;
    Ui::PayFood* ui;
};

#endif // PAYFOOD_H
