#include "rollresources.h"
#include "ui_rollresources.h"


RollResources::RollResources(const int workerAmount, const Resource resource, std::shared_ptr<Player>player, QWidget *parent)
    : QDialog(parent), ui(new Ui::RollResources), m_resource(resource), m_text(resourceToString(resource)), m_player(player){

    ui->setupUi(this);
    QString name = player->getString();
    this->setWindowTitle(name);
    int amount = 0;
    for (int i = 0; i < workerAmount; ++i) {
        amount += rand() % 6 + 1;
    }
    m_roll = amount;

    ui->Tool1Label->setText("+" + QString::number(m_player->getTools()[0].getLevel()));
    ui->Tool2Label->setText("+" + QString::number(m_player->getTools()[1].getLevel()));
    ui->Tool3Label->setText("+" + QString::number(m_player->getTools()[2].getLevel()));
    ui->Tool1Button->setDisabled(m_player->getTools()[0].wasUsed());
    ui->Tool2Button->setDisabled(m_player->getTools()[1].wasUsed());
    ui->Tool3Button->setDisabled(m_player->getTools()[2].wasUsed());
    tempTools(player->getExtraTools());
    m_gain = m_roll/(int) m_resource;
    ui->message->setText("You rolled " + QString::number(m_roll) + " which will give you " + QString::number(m_gain) + " " + m_text);
}



RollResources::~RollResources(){
    delete ui;
}

int RollResources::getGain(){
    return m_gain;

}

void RollResources::tempTools(std::vector<int> tools){
    switch (tools.size()){
    case(0):
        ui->tempTool1Button->setVisible(false);
        ui->tempTool1Label->setVisible(false);
        ui->tempTool2Button->setVisible(false);
        ui->tempTool2Label->setVisible(false);
        ui->tempTool3Button->setVisible(false);
        ui->tempTool3Label->setVisible(false);
        return;
    case (1):
        ui->tempTool1Label->setText("+" + QString::number(tools[0]));
        ui->tempTool2Button->setVisible(false);
        ui->tempTool2Label->setVisible(false);
        ui->tempTool3Button->setVisible(false);
        ui->tempTool3Label->setVisible(false);
        return;
    case (2):
        ui->tempTool1Label->setText("+" + QString::number(tools[0]));
        ui->tempTool2Label->setText("+" + QString::number(tools[1]));
        ui->tempTool3Button->setVisible(false);
        ui->tempTool3Label->setVisible(false);
        return;
    case(3):
        ui->tempTool1Label->setText("+" + QString::number(tools[0]));
        ui->tempTool2Label->setText("+" + QString::number(tools[1]));
        ui->tempTool3Label->setText("+" + QString::number(tools[2]));
        return;
    }
}

void RollResources::on_pushButton_clicked(){
    this->close();
}

void RollResources::on_Tool1Button_clicked(){
    ui->Tool1Button->setDisabled(true);
    m_player->disableTool(0);
    m_roll += m_player->getTools()[0].getLevel();
    m_gain = m_roll/(int) m_resource;
    ui->message->setText("You rolled " + QString::number(m_roll) + " which will give you " + QString::number(m_gain) + " " + m_text);
}

void RollResources::on_Tool2Button_clicked(){
    ui->Tool2Button->setDisabled(true);
    m_player->disableTool(1);
    m_roll += m_player->getTools()[1].getLevel();
    m_gain = m_roll/(int) m_resource;
    ui->message->setText("You rolled " + QString::number(m_roll) + " which will give you " + QString::number(m_gain) + " " + m_text);

}

void RollResources::on_Tool3Button_clicked(){
    ui->Tool3Button->setDisabled(true);
    m_player->disableTool(2);
    m_roll += m_player->getTools()[2].getLevel();
    m_gain = m_roll/(int) m_resource;
    ui->message->setText("You rolled " + QString::number(m_roll) + " which will give you " + QString::number(m_gain) + " " + m_text);

}


const QString RollResources::resourceToString(Resource resource)
{
    switch(resource){
    case(Resource::food):
        return "food";
    case(Resource::wood):
        return "wood";
    case(Resource::clay):
        return "clay";
    case(Resource::stone):
        return "stone";
    case(Resource::gold):
        return "gold";
    default:
        return "error: no resource given";
    }
}

void RollResources::on_tempTool3Button_clicked(){
    ui->tempTool3Button->setDisabled(true);
    QString number = ui->tempTool3Label->text()[1];
    int amount = number.toInt();
    m_player->deleteExtraTool(amount);
    m_roll += amount;
    m_gain = m_roll/(int) m_resource;
    ui->message->setText("You rolled " + QString::number(m_roll) + " which will give you " + QString::number(m_gain) + " " + m_text);
}

void RollResources::on_tempTool2Button_clicked(){
    ui->tempTool2Button->setDisabled(true);
    QString number = ui->tempTool2Label->text()[1];
    int amount = number.toInt();
    m_player->deleteExtraTool(amount);
    m_roll += amount;
    m_gain = m_roll/(int) m_resource;
    ui->message->setText("You rolled " + QString::number(m_roll) + " which will give you " + QString::number(m_gain) + " " + m_text);
}

void RollResources::on_tempTool1Button_clicked(){
    ui->tempTool1Button->setDisabled(true);
    QString number = ui->tempTool1Label->text()[1];
    int amount = number.toInt();
    m_player->deleteExtraTool(amount);
    m_roll += amount;
    m_gain = m_roll/(int) m_resource;
    ui->message->setText("You rolled " + QString::number(m_roll) + " which will give you " + QString::number(m_gain) + " " + m_text);
}
