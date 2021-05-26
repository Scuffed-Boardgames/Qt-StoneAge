#include "varbuildingpay.h"
#include "ui_varbuildingpay.h"

VarBuildingPay::VarBuildingPay(std::shared_ptr<Player> player, std::shared_ptr<VarBuilding> building, QWidget *parent)
    :QDialog(parent), m_bought(false), ui(new Ui::VarBuildingPay), m_player(player), m_building(building){
    ui->setupUi(this);
    connect(ui->woodAmount, &QSpinBox::valueChanged, this, &VarBuildingPay::editText);
    connect(ui->clayAmount, &QSpinBox::valueChanged, this, &VarBuildingPay::editText);
    connect(ui->stoneAmount, &QSpinBox::valueChanged, this, &VarBuildingPay::editText);
    connect(ui->goldAmount, &QSpinBox::valueChanged, this, &VarBuildingPay::editText);
    this->setWindowTitle(player->getString());
    m_bought = false;
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
        textDiff = " of " + QString::number(diff) + " types";
    }
    ui->topText->setText("You still have to pay " + amount + " items" + textDiff);
    ui->okayButton->setEnabled(false);
}

VarBuildingPay::~VarBuildingPay(){
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
int VarBuildingPay::getDiff(){
    int diff = 0;
    for (int i = 3; i < 7; ++i){
        if(getAmount((Resource)i) > 0){
            ++diff;
        }
    }
    return diff;
}

void VarBuildingPay::editText(){
    int amount = 0;
    int diff = getDiff();

    int woodAmount = getAmount(Resource::wood);
    amount += woodAmount;

    int clayAmount = getAmount(Resource::clay);
    amount += clayAmount;

    int stoneAmount = getAmount(Resource::stone);
    amount += stoneAmount;

    int goldAmount = getAmount(Resource::gold);
    amount += goldAmount;

    int reqDiff = m_building->getDiff() - diff;
    if(reqDiff < 0){
        reqDiff = 0;
    }

    QString textAmount;
    int max = m_building->getTotalMax();
    int min = m_building->getTotalMin();
    int reqAmount = max - amount;

    if(max == min){
        textAmount = QString::number(reqAmount);
        ui->okayButton->setEnabled(reqAmount == 0);
    } else{
        if(amount > 0){
            min = 0;
        }
        if(amount == max){
            textAmount = "0";
        }else{
            textAmount = QString::number(min) + "-" + QString::number(reqAmount);
        }
        ui->okayButton->setEnabled(amount > 0);
    }
    QString stringDiff = "";
    if(m_building->getDiff() > 0){
        stringDiff =  " of " + QString::number(reqDiff) + " types";
    }
    ui->topText->setText("You still have to pay " + textAmount + " items" + stringDiff);
    ui->bottomText->setText("this will give you " + QString::number(m_building->calcScore(woodAmount, clayAmount, stoneAmount, goldAmount)) + " score");
    ui->woodAmount->setMaximum(woodAmount + reqAmount);
    ui->clayAmount->setMaximum(clayAmount + reqAmount);
    ui->stoneAmount->setMaximum(stoneAmount + reqAmount);
    ui->goldAmount->setMaximum(goldAmount + reqAmount);
    if(reqDiff == 0 && m_building->getDiff() > 0){
        if(woodAmount == 0){
            ui->woodAmount->setMaximum(0);
        }
        if(clayAmount == 0){
            ui->clayAmount->setMaximum(0);
        }
        if(stoneAmount == 0){
            ui->stoneAmount->setMaximum(0);
        }
        if(goldAmount == 0){
            ui->goldAmount->setMaximum(0);
        }
    }
    if(ui->okayButton->isEnabled())
        ui->okayButton->setEnabled(m_building->canPay(m_player, woodAmount, clayAmount, stoneAmount, goldAmount));
    if(ui->okayButton->isEnabled())
        ui->okayButton->setEnabled(reqDiff == 0);
}

void VarBuildingPay::resetAmounts(){
    ui->woodAmount->setValue(0);
    ui->clayAmount->setValue(0);
    ui->stoneAmount->setValue(0);
    ui->goldAmount->setValue(0);
}

void VarBuildingPay::on_okayButton_clicked(){
    resetAmounts();
    m_bought = m_building->build(m_player, ui->woodAmount->value(), ui->clayAmount->value(), ui->stoneAmount->value(), ui->goldAmount->value());
    m_building = nullptr;
    m_player = nullptr;
    this->close();
}

void VarBuildingPay::on_cancelButton_clicked(){
    resetAmounts();
    m_building->reset();
    m_building = nullptr;
    m_player = nullptr;
    this->close();
}

bool VarBuildingPay::getBought() const{
    return m_bought;
}
