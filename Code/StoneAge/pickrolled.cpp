#include "pickrolled.h"
#include "ui_pickrolled.h"

PickRolled::PickRolled(std::shared_ptr<Player> player, int die1, int die2, int die3, int die4, QWidget *parent) :
    QDialog(parent), ui(new Ui::PickRolled), m_player{player}
{
    ui->setupUi(this);
    m_resources[0] = die1;
    m_resources[1] = die2;
    m_resources[2] = die3;
    m_resources[3] = die4;
    assignResources();
}

PickRolled::~PickRolled()
{
    delete ui;
}

void PickRolled::giveResource(QString resource)
{
    if(resource == "Wood"){
        m_player->addResource(Resource::wood, 1);
    }else if(resource == "Clay"){
        m_player->addResource(Resource::clay, 1);
    }else if(resource == "Stone"){
        m_player->addResource(Resource::stone, 1);
    }else if(resource == "Gold"){
        m_player->addResource(Resource::gold, 1);
    }else if(resource == "Tool"){
        m_player->addTool();
    }else if(resource == "Food Gain"){
        m_player->addTool();
    }
}

void PickRolled::assignResources()
{
    for(int i = 0; i < 4; ++i){
        switch(m_resources[i]){
        case(1):
            ui->resourceBox->addItem("Wood");
            return;
        case(2):
            ui->resourceBox->addItem("Clay");
            return;
        case(3):
            ui->resourceBox->addItem("Stone");
            return;
        case(4):
            ui->resourceBox->addItem("Gold");
            return;
        case(5):
            ui->resourceBox->addItem("Tool");
            return;
        case(6):
            ui->resourceBox->addItem("Food Gain");
            return;
        default:
            return;
        }
    }
}

void PickRolled::assignDice(int die1, int die2, int die3, int die4)
{
    m_resources[0] = die1;
    m_resources[1] = die2;
    m_resources[2] = die3;
    m_resources[3] = die4;
    assignResources();
}

void PickRolled::assignPlayer(std::shared_ptr<Player> player)
{
    m_player = player;
}

void PickRolled::on_okayButton_clicked()
{
    giveResource(ui->resourceBox->currentText());
    ui->resourceBox->removeItem(ui->resourceBox->currentIndex());
}
