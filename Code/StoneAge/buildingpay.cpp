#include "buildingpay.h"
#include "ui_buildingpay.h"

BuildingPay::BuildingPay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuildingPay)
{
    ui->setupUi(this);
}

void BuildingPay::setBuilding(Player *player, Building *building)
{
    m_player = player;
    m_building = building;
    ui->woodText->setDisabled(true);
    ui->clayText->setDisabled(true);
    ui->stoneText->setDisabled(true);
    ui->stoneText->setDisabled(true);
    SetBuilding* setbuilding = dynamic_cast<SetBuilding*>(building);
    if(setbuilding){
           ui->woodText->setEnabled(setbuilding->getCost(Resource::wood) != 0);
           ui->woodText->setText("Wood: " + QString::number(setbuilding->getCost(Resource::wood)));
           ui->clayText->setEnabled(setbuilding->getCost(Resource::clay) != 0);
           ui->clayText->setText("Clay: " + QString::number(setbuilding->getCost(Resource::clay)));
           ui->stoneText->setEnabled(setbuilding->getCost(Resource::stone) != 0);
           ui->stoneText->setText("Stone: " + QString::number(setbuilding->getCost(Resource::stone)));
           ui->stoneText->setEnabled(setbuilding->getCost(Resource::gold) != 0);
           ui->stoneText->setText("Gold: " + QString::number(setbuilding->getCost(Resource::gold)));
    }
}

BuildingPay::~BuildingPay()
{
    delete ui;
}
