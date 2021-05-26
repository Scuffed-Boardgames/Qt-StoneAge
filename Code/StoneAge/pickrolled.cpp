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
    for(int i = 0; i<4; ++i){
        m_chosen[i] = false;
    }
    assignResources();
}

PickRolled::PickRolled(const QJsonObject &json) :
    QDialog(nullptr), ui(new Ui::PickRolled), m_player{nullptr}
{
    ui->setupUi(this);
    m_resources[0] = json["die1"].toInt();
    m_resources[1] = json["die2"].toInt();
    m_resources[2] = json["die3"].toInt();
    m_resources[3] = json["die4"].toInt();
    m_chosen[0] = json["red"].toBool();
    m_chosen[1] = json["blue"].toBool();
    m_chosen[2] = json["yellow"].toBool();
    m_chosen[3] = json["green"].toBool();
    assignResources();
}

PickRolled::~PickRolled()
{
    delete ui;
}

QJsonObject PickRolled::save()
{
    QJsonObject json = {{"red", hasChosen(Colour::red)},
                        {"blue", hasChosen(Colour::blue)},
                        {"yellow", hasChosen(Colour::yellow)},
                        {"green", hasChosen(Colour::green)},
                        {"die1", m_resources[0]},
                        {"die2", m_resources[1]},
                        {"die3", m_resources[2]},
                        {"die4", m_resources[3]}
                        };
    return json;
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
            break;
        case(2):
            ui->resourceBox->addItem("Clay");
            break;
        case(3):
            ui->resourceBox->addItem("Stone");
            break;
        case(4):
            ui->resourceBox->addItem("Gold");
            break;
        case(5):
            ui->resourceBox->addItem("Tool");
            break;
        case(6):
            ui->resourceBox->addItem("Food Gain");
            break;
        default:
            break;
        }
    }
}

void PickRolled::assignPlayer(std::shared_ptr<Player> player){
    m_player = player;
}

void PickRolled::on_okayButton_clicked(){
    giveResource(ui->resourceBox->currentText());
    ui->resourceBox->removeItem(ui->resourceBox->currentIndex());
    m_chosen[(int)m_player->getColour()] = true;
    this->close();
}

bool PickRolled::hasChosen(Colour colour)
{
    return m_chosen[(int)colour];
}
