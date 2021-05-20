#include "showbonus.h"
#include "ui_showbonus.h"

ShowBonus::ShowBonus(int farmers, int makers, int builders, int shamen, int bonus, std::shared_ptr<Player>player, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowBonus)
{
    ui->setupUi(this);
    this->setWindowTitle(player->getString());
    if(farmers != 0){
        ui->label->setText("You receive " + QString::number(farmers) + "farmer(s)");
    }else if(makers != 0){
        ui->label->setText("You receive " + QString::number(makers) + "tool maker(s)");
    }else if(builders != 0){
        ui->label->setText("You receive " + QString::number(builders) + "hut builder(s)");
    }else if(shamen != 0){
        ui->label->setText("You receive " + QString::number(shamen) + "shaman(s)");
    }else{
        ui->label->setText("You receive " + bonusToString(bonus));
    }
}

ShowBonus::~ShowBonus()
{
    delete ui;
}

const QString ShowBonus::bonusToString(int resource)
{
    switch(resource){
    case(0):
        return "art";
    case(1):
        return "healing";
    case(2):
        return "music";
    case(3):
        return "pottery";
    case(4):
        return "time";
    case(5):
        return "transport";
    case(6):
        return "weaving";
    case(7):
        return "writing";
    default:
        return "none";
    }
}

void ShowBonus::on_okButton_clicked()
{
    this->close();
}
