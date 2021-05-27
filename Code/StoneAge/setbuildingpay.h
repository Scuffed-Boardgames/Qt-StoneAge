// Denzell Mgbokwere 2054872
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
    ~SetBuildingPay();

    bool getBought() const;
    SetBuildingPay(std::shared_ptr<Player> player, std::shared_ptr<SetBuilding> building, QWidget *parent = nullptr);
private slots:
    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::SetBuildingPay *ui;
    std::shared_ptr<SetBuilding> m_building;
    std::shared_ptr<Player> m_player;

    bool m_bought;
    int m_woodCost;
    int m_clayCost;
    int m_stoneCost;
    int m_goldCost;

};

#endif // SETBUILDINGPAY_H
