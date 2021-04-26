#include "rollresources.h"
#include "ui_rollresources.h"


RollResources::RollResources(const int workerAmount, const Resource resource, const QString text, std::shared_ptr<Player>player, QWidget *parent)
    : QWidget(parent), ui(new Ui::RollResources), m_resource(resource), m_text(text), m_player(player)
{
    ui->setupUi(this);
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

    m_gain = m_roll/(int) m_resource;
    ui->message->setText("You rolled " + QString::number(m_roll) + " which will give you " + QString::number(m_gain) + " " + m_text);
}



RollResources::~RollResources()
{
    delete ui;
}

int RollResources::getGain(){
    return m_gain;

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
