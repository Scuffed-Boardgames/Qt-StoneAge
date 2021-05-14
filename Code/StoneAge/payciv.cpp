#include "payciv.h"
#include "ui_payciv.h"

PayCiv::PayCiv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PayCiv)
{
    ui->setupUi(this);
}

PayCiv::~PayCiv()
{
    delete ui;
}
