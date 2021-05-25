#include "showcivreward.h"
#include "ui_showcivreward.h"

ShowCivReward::ShowCivReward(std::shared_ptr<Player>player, bool card, bool food, bool score, bool tool, bool xtool, int resource, int amount, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowCivReward)
{
    ui->setupUi(this);
    this->setWindowTitle(player->getString());
    if(card){
        ui->label->setText("You received another card");
    }else if(food){
        ui->label->setText("You received +1 food gain");
    }else if(score){
        ui->label->setText("You received +3 score");
    }else if(tool){
        ui->label->setText("You received +1 tool");
    }else if(xtool){
        ui->label->setText("You received an extra tool");
    }else{
        ui->label->setText("You received " + QString::number(amount) + " " + resourceToString((Resource)resource));
    }
}

ShowCivReward::~ShowCivReward()
{
    delete ui;
}

const QString ShowCivReward::resourceToString(Resource resource)
{
    switch(resource){
    case(Resource::food):
        return "food";
    case(Resource::wood):
        return "wood";
    case(Resource::clay):
        return "clay";
    case(Resource::stone):
        return "stone";
    case(Resource::gold):
        return "gold";
    default:
        return "none";
    }
}

void ShowCivReward::on_pushButton_clicked()
{
    this->close();
}
