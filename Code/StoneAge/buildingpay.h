#ifndef BUILDINGPAY_H
#define BUILDINGPAY_H

#include <QDialog>
#include "setbuilding.h"

namespace Ui {
class BuildingPay;
}

class BuildingPay : public QDialog
{
    Q_OBJECT

public:
    explicit BuildingPay(QWidget *parent = nullptr);
    void setBuilding(Player* player, Building* building);
    ~BuildingPay();

private:
    Ui::BuildingPay *ui;
    Building* m_building;
    Player* m_player;

};

#endif // BUILDINGPAY_H
