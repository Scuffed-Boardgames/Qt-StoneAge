// Bernd Uijtdebroeks 2055267
#ifndef SHOWBONUS_H
#define SHOWBONUS_H

#include <QDialog>
#include "player.h"

namespace Ui {
class ShowBonus;
}

class ShowBonus : public QDialog
{
    Q_OBJECT

public:
    explicit ShowBonus(int farmers, int makers, int builders, int shamen, int bonus, std::shared_ptr<Player> player,QWidget *parent = nullptr);
    ~ShowBonus();

private slots:
    void on_okButton_clicked();

private:
    Ui::ShowBonus *ui;
    const QString bonusToString(int resource);
};

#endif // SHOWBONUS_H
