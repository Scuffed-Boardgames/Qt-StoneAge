#include "workeradd.h"
#include "ui_workeradd.h"

workerAdd::workerAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workerAdd)
{
    ui->setupUi(this);
}

workerAdd::~workerAdd()
{
    delete ui;
}

void workerAdd::on_okayButton_clicked()
{
    m_amount = ui->amount->value();
    this->close();
}

void workerAdd::on_cancelButton_clicked()
{
    m_amount = 0;
    this->close();
}

int workerAdd::getAmount(){
    return m_amount;
}

void workerAdd::setFixed(int amount){
    ui->amount->setValue(amount);
    ui->amount->setVisible(false);
    ui->label->setText("Placing " +QString::number(amount)+" workers on this space");
}
