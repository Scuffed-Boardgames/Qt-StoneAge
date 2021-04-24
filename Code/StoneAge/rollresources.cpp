#include "rollresources.h"
#include "ui_rollresources.h"


RollResources::RollResources(int workerAmount, Resource resource, QString text, QWidget *parent) : QWidget(parent), ui(new Ui::RollResources)
{
    ui->setupUi(this);
    int amount = 0;
    for (int i = 0; i < workerAmount; ++i) {
        amount += rand() % 6 + 1;
    }
    m_gain = amount/(int) resource;
    ui->message->setText("You rolled " + QString::number(amount) + " which will give you " + QString::number(m_gain) + " " + text);
}



RollResources::~RollResources()
{
    delete ui;
}

int RollResources::getGain(){
    return m_gain;

}

void RollResources::on_pushButton_clicked()
{
    this->close();
}
