#ifndef VARBUILDINGPAY_H
#define VARBUILDINGPAY_H

#include <QDialog>
#include "player.h"
#include "varbuilding.h"

namespace Ui {
class VarBuildingPay;
}

class VarBuildingPay : public QDialog
{
    Q_OBJECT

public:
    explicit VarBuildingPay(QWidget *parent = nullptr);
    ~VarBuildingPay();

    void setBuilding(std::shared_ptr<Player> player, std::shared_ptr<VarBuilding> building);
    void resetAmounts();

    bool getBought() const;
    int getAmount(Resource resource);

public slots:
    void editText();

private slots:
    void on_okayButton_clicked();
    void on_cancelButton_clicked();

private:
    bool m_bought;
    Ui::VarBuildingPay *ui;
    std::shared_ptr<Player> m_player;
    std::shared_ptr<VarBuilding> m_building;
    int getDiff();
};

#endif // VARBUILDINGPAY_H
