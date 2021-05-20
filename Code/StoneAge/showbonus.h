#ifndef SHOWBONUS_H
#define SHOWBONUS_H

#include <QDialog>

namespace Ui {
class ShowBonus;
}

class ShowBonus : public QDialog
{
    Q_OBJECT

public:
    explicit ShowBonus(QWidget *parent = nullptr);
    ~ShowBonus();

private:
    Ui::ShowBonus *ui;
};

#endif // SHOWBONUS_H
