#include "workeradd.h"
#include "ui_workeradd.h"

WorkerAdd::WorkerAdd(QWidget *parent) : QWidget(parent), ui(new Ui::WorkerAdd)
{
    ui->setupUi(this);
}

void WorkerAdd::addToPlace(Place* place, const Colour colour)
{
    m_place = place;
    m_colour = colour;
}

WorkerAdd::~WorkerAdd()
{
    delete ui;
}

void WorkerAdd::on_okayButton_clicked()
{
    if(m_place)
        m_place->addWorkers(ui->amount->value(), m_colour);
    ui->amount->setValue(1);
    m_place = nullptr;
    this->close();
}

void WorkerAdd::on_cancelButton_clicked()
{
    ui->amount->setValue(1);
    m_place = nullptr;
    this->close();
}


void WorkerAdd::setStatic(const int amount){
    ui->amount->setValue(amount);
    ui->amount->setVisible(false);
    ui->label->setText("Placing " +QString::number(amount)+" workers on this space");
}

void WorkerAdd::setDynamic()
{
    ui->amount->setValue(1);
    ui->amount->setVisible(true);
    ui->label->setText("How many workers do you want to add?");

}
