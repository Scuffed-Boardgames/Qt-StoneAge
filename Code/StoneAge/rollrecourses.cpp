#include "rollrecourses.h"
#include "ui_rollrecourses.h"


RollRecourses::RollRecourses(int workerAmount, Recourse recourse, QString text, QWidget *parent) : QWidget(parent), ui(new Ui::RollRecourses)
{
    ui->setupUi(this);
    int amount = 0;
    for (int i = 0; i < workerAmount; ++i) {
        amount += rand() % 6 + 1;
    }
    m_gain = amount/(int) recourse;
    ui->message->setText("You rolled " + QString::number(amount) + " which will give you " + QString::number(m_gain) + " " + text);
}



RollRecourses::~RollRecourses()
{
    delete ui;
}

int RollRecourses::getGain(){
    return m_gain;

}

void RollRecourses::on_pushButton_clicked()
{
    this->close();
}
