// Bernd Uijtdebroeks 2055267
#include "payfood.h"
#include "ui_payfood.h"

PayFood::PayFood(std::shared_ptr<Player> player, int amount)
    : QDialog(nullptr), m_player{player}, m_amount{amount}, ui(new Ui::PayFood){

    ui->setupUi(this);
    this->setWindowTitle(player->getString());
    ui->payLabel->setText("You still have to pay " + QString::number(m_amount) + " items or take -10 score");
    connect(ui->spinBoxWood, &QSpinBox::valueChanged, this, &PayFood::editText);
    connect(ui->spinBoxClay, &QSpinBox::valueChanged, this, &PayFood::editText);
    connect(ui->spinBoxStone, &QSpinBox::valueChanged, this, &PayFood::editText);
    connect(ui->spinBoxGold, &QSpinBox::valueChanged, this, &PayFood::editText);
    ui->spinBoxWood->setMaximum(player->getResource(Resource::wood));
    ui->spinBoxClay->setMaximum(player->getResource(Resource::clay));
    ui->spinBoxStone->setMaximum(player->getResource(Resource::stone));
    ui->spinBoxGold->setMaximum(player->getResource(Resource::gold));
}

void PayFood::editText(){
    int total = totalSet();
    int needed = m_amount - total;
    ui->payLabel->setText("You still have to pay " + QString::number(needed) + " items or take -10 score");

    ui->spinBoxWood->setMaximum(std::min(m_player->getResource(Resource::wood), ui->spinBoxWood->value() + needed));
    ui->spinBoxClay->setMaximum(std::min(m_player->getResource(Resource::clay), ui->spinBoxWood->value() + needed));
    ui->spinBoxStone->setMaximum(std::min(m_player->getResource(Resource::stone), ui->spinBoxWood->value() + needed));
    ui->spinBoxGold->setMaximum(std::min(m_player->getResource(Resource::gold), ui->spinBoxWood->value() + needed));

    ui->acceptButton->setEnabled(needed == 0);
}
PayFood::~PayFood(){
    delete ui;
}

void PayFood::on_scoreButton_clicked(){
    m_player->addScore(-10);
    m_player = nullptr;
    this->close();
}

int PayFood::totalSet(){
    int total = 0;
    total += ui->spinBoxWood->value();
    total += ui->spinBoxClay->value();
    total += ui->spinBoxStone->value();
    total += ui->spinBoxGold->value();
    return total;
}

void PayFood::removeResources(){
    m_player->addResource(Resource::wood, -ui->spinBoxWood->value());
    m_player->addResource(Resource::clay, -ui->spinBoxClay->value());
    m_player->addResource(Resource::stone, -ui->spinBoxStone->value());
    m_player->addResource(Resource::gold, -ui->spinBoxGold->value());
}

void PayFood::on_acceptButton_clicked(){
    int total = totalSet();
    if(total != m_amount){
        return;
    }
    removeResources();
    m_player = nullptr;
    this->close();
}
