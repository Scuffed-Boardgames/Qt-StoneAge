#include "workeradd.h"
#include "ui_workeradd.h"

workerAdd::workerAdd(QWidget *parent) : QWidget(parent), ui(new Ui::workerAdd)
{
    ui->setupUi(this);
}

void workerAdd::addToPlace(placeView *place, Colour colour)
{
    m_place = place;
    m_colour = colour;
}

workerAdd::~workerAdd()
{
    delete ui;
}

void workerAdd::on_okayButton_clicked()
{
    m_place->addWorkers(ui->amount->value(), m_colour);
    ui->amount->setValue(0);
    this->close();
}

void workerAdd::on_cancelButton_clicked()
{
    ui->amount->setValue(0);
    this->close();
}


void workerAdd::setFixed(int amount){
    ui->amount->setValue(amount);
    ui->amount->setVisible(false);
    ui->label->setText("Placing " +QString::number(amount)+" workers on this space");
}
