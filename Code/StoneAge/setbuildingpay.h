#ifndef SETBUILDINGPAY_H
#define SETBUILDINGPAY_H

#include <QDialog>
#include "setbuilding.h"

namespace Ui {
class SetBuildingPay;
}

class SetBuildingPay : public QDialog
{
    Q_OBJECT

public:
    explicit SetBuildingPay(QWidget *parent = nullptr);
    void setBuilding(std::shared_ptr<Player> player, std::shared_ptr<SetBuilding> building);
    ~SetBuildingPay();

private slots:
    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::SetBuildingPay *ui;
    std::shared_ptr<SetBuilding> m_building;
    std::shared_ptr<Player> m_player;

    int m_woodCost;
    int m_clayCost;
    int m_stoneCost;
    int m_goldCost;

};

#endif // SETBUILDINGPAY_H
