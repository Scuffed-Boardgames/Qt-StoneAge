// Denzell Mgbokwere 2054872
#ifndef VARBUILDINGPAY_H
#define VARBUILDINGPAY_H

#include <QDialog>
#include "varbuilding.h"

namespace Ui {
class VarBuildingPay;
}

class VarBuildingPay : public QDialog
{
    Q_OBJECT

public:
    explicit VarBuildingPay(std::shared_ptr<Player> player, std::shared_ptr<VarBuilding> building, QWidget *parent = nullptr);
    ~VarBuildingPay();

    bool getBought() const;
    int getAmount(Resource resource);

private slots:
    void editText(); // Updates the boxes and text
    void on_okayButton_clicked();
    void on_cancelButton_clicked();

private:
    bool m_bought;
    Ui::VarBuildingPay *ui;
    std::shared_ptr<Player> m_player;
    std::shared_ptr<VarBuilding> m_building;

    void resetAmounts();
    int getDiff();
};

#endif // VARBUILDINGPAY_H
