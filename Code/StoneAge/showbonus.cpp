#include "showbonus.h"
#include "ui_showbonus.h"

ShowBonus::ShowBonus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowBonus)
{
    ui->setupUi(this);
}

ShowBonus::~ShowBonus()
{
    delete ui;
}
