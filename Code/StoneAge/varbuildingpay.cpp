#include "varbuildingpay.h"
#include "ui_varbuildingpay.h"

VarBuildingPay::VarBuildingPay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VarBuildingPay)
{
    ui->setupUi(this);
    connect(ui->woodAmount, &QSpinBox::valueChanged, this, &VarBuildingPay::editText);
    connect(ui->clayAmount, &QSpinBox::valueChanged, this, &VarBuildingPay::editText);
    connect(ui->stoneAmount, &QSpinBox::valueChanged, this, &VarBuildingPay::editText);
    connect(ui->goldAmount, &QSpinBox::valueChanged, this, &VarBuildingPay::editText);
}

void VarBuildingPay::setBuilding(std::shared_ptr<Player> player, std::shared_ptr<VarBuilding> building)
{
    m_player = player;
    m_building = building;
    int max = m_building->getTotalMax();
    int min = m_building->getTotalMin();
    QString amount;
    if(max == min){
        amount = QString::number(min);
    } else{
        amount = QString::number(min) + "-" + QString::number(max);
    }

    int diff = m_building->getDiff();
    QString textDiff;
    if(diff == 0){
        textDiff = "";
    } else{
        textDiff = "items of " + QString::number(diff) + " types";
    }
    ui->topText->setText("You still have to pay" + amount + textDiff);
}

VarBuildingPay::~VarBuildingPay()
{
    delete ui;
}



int VarBuildingPay::getAmount(Resource resource){
    switch (resource){
    case(Resource::wood):
        return ui->woodAmount->value();
    case(Resource::clay):
        return ui->clayAmount->value();
    case(Resource::stone):
        return ui->stoneAmount->value();
    case(Resource::gold):
        return ui->goldAmount->value();
    default:
        return 0;
    }
}

void VarBuildingPay::editText(int num)
{
    int amount = 0;
    int diff = 0;

    int woodAmount = getAmount(Resource::wood);
    if(woodAmount > 0)
        ++diff;
    amount += woodAmount;

    int clayAmount = getAmount(Resource::clay);
    if(clayAmount > 0)
        ++diff;
    amount += clayAmount;

    int stoneAmount = getAmount(Resource::stone);
    if(stoneAmount > 0)
        ++diff;
    amount += stoneAmount;

    int goldAmount = getAmount(Resource::gold);
    if(goldAmount > 0)
        ++diff;
    amount += goldAmount;

    diff -= m_building->getDiff();
    if(diff < 0){
        diff = 0;
    }
    QString textAmount;
    int max = m_building->getTotalMax();
    int min = m_building->getTotalMin();
    amount -= max;

    if(max == min){
        textAmount = QString::number(amount);
    } else{
        textAmount = QString::number(min) + "-" + QString::number(amount);
    }
    ui->topText->setText("You still have to pay" + textAmount + "items of " + QString::number(diff) + " types");
    ui->bottomText->setText("this will give you " + QString::number(m_building->calcScore(woodAmount, clayAmount, stoneAmount, goldAmount)) + " score");
    ui->woodAmount->setMaximum(woodAmount + amount - max);
    ui->clayAmount->setMaximum(clayAmount + amount - max);
    ui->stoneAmount->setMaximum(stoneAmount + amount - max);
    ui->goldAmount->setMaximum(goldAmount + amount - max);
    ui->okayButton->setEnabled(m_building->canPay(m_player, woodAmount, clayAmount, stoneAmount, goldAmount));

}

void VarBuildingPay::on_okayButton_clicked()
{
    m_building->build(m_player, ui->woodAmount->value(), ui->clayAmount->value(), ui->stoneAmount->value(), ui->goldAmount->value());
    m_building = nullptr;
    m_player = nullptr;
    this->close();
}

void VarBuildingPay::on_cancelButton_clicked()
{
    m_building->reset();
    m_building = nullptr;
    m_player = nullptr;
    this->close();
}
