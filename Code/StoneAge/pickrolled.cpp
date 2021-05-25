#include "pickrolled.h"
#include "ui_pickrolled.h"

PickRolled::PickRolled(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PickRolled)
{
    ui->setupUi(this);
}

PickRolled::~PickRolled()
{
    delete ui;
}
