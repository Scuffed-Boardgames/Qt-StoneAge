#include "payfood.h"
#include "ui_payfood.h"

PayFood::PayFood(std::shared_ptr<Player> player, int amount) : m_player{player}, m_amount{amount}
{
    ui->setupUi(this);
    this->setWindowTitle(colourToString(player->getColour()));
    ui->payLabel->setText("You have to pay " + QString::number(m_amount) + " items or take -10 score");
    ui->spinBoxWood->setMaximum(player->getResource(Resource::wood));
    ui->spinBoxClay->setMaximum(player->getResource(Resource::clay));
    ui->spinBoxStone->setMaximum(player->getResource(Resource::stone));
    ui->spinBoxGold->setMaximum(player->getResource(Resource::gold));
}

PayFood::~PayFood()
{
    delete ui;
}

void PayFood::on_scoreButton_clicked()
{
    m_player->addScore(-10);
    m_player = nullptr;
    this->close();
}

int PayFood::totalSet()
{
    int total = 0;
    total += ui->spinBoxWood->value();
    total += ui->spinBoxClay->value();
    total += ui->spinBoxStone->value();
    total += ui->spinBoxGold->value();
    return total;
}

void PayFood::removeResources()
{
    m_player->addResource(Resource::wood, -ui->spinBoxWood->value());
    m_player->addResource(Resource::clay, -ui->spinBoxClay->value());
    m_player->addResource(Resource::stone, -ui->spinBoxStone->value());
    m_player->addResource(Resource::gold, -ui->spinBoxGold->value());
}

void PayFood::on_acceptButton_clicked()
{
    int total = totalSet();
    if(total != m_amount){
        return;
    }
    removeResources();
    m_player = nullptr;
    this->close();
}

QString PayFood::colourToString(Colour colour)
{
    switch(colour){
    case(Colour::red):
        return "Red player";
    case(Colour::blue):
        return "Blue player";
    case(Colour::yellow):
        return "Yellow player";
    case(Colour::green):
        return "Green player";
    default:
        return "error: no colour given";
    }
}
