#include "setbuildingpay.h"
#include "ui_setbuildingpay.h"
#include "ui_buildingpay.h"

SetBuildingPay::SetBuildingPay(QWidget *parent) :
     QDialog(parent),
    ui(new Ui::SetBuildingPay),  m_bought(false)
{
    ui->setupUi(this);
}

void SetBuildingPay::setBuilding(std::shared_ptr<Player> player, std::shared_ptr<SetBuilding> building)
{
    this->setWindowTitle(player->getString());
    m_bought = false;
    m_player = player;
    m_building = building;

    m_woodCost = building->getCost(Resource::wood);
    ui->woodText->setVisible(m_woodCost != 0);
    ui->woodText->setText("Wood: " + QString::number(m_woodCost));

    m_clayCost = building->getCost(Resource::clay);
    ui->clayText->setVisible(m_clayCost != 0);
    ui->clayText->setText("Clay: " + QString::number(m_clayCost));

    m_stoneCost = building->getCost(Resource::stone);
    ui->stoneText->setVisible(m_stoneCost != 0);
    ui->stoneText->setText("Stone: " + QString::number(m_stoneCost));

    m_goldCost = building->getCost(Resource::gold);
    ui->goldText->setVisible(m_goldCost != 0);
    ui->goldText->setText("Gold: " + QString::number(m_goldCost));

    ui->bottomText->setText("and will give you " + QString::number(building->getScoreGain()) + " score");
    ui->yesButton->setEnabled(building->canPay(m_player));
}

SetBuildingPay::~SetBuildingPay()
{
    delete ui;
}

void SetBuildingPay::on_yesButton_clicked()
{
    m_bought = m_building->build(m_player);
    m_player = nullptr;
    m_building = nullptr;
    this->close();
}

void SetBuildingPay::on_noButton_clicked()
{
    m_building->reset();
    m_player = nullptr;
    m_building = nullptr;
    this->close();
}

bool SetBuildingPay::getBought() const
{
    return m_bought;
}
