#include "payciv.h"
#include "ui_payciv.h"

PayCiv::PayCiv(std::shared_ptr<Player> player, std::shared_ptr<Civilisation> civCard)
    : QDialog(nullptr), m_player{player}, m_civ{civCard}, m_amount{m_civ->getCost()}, m_hasPayed{false}, ui(new Ui::PayCiv){

    ui->setupUi(this);
    this->setWindowTitle(player->getString());
    ui->payLabel->setText("You have to pay " + QString::number(m_amount) + " items for this card");
    ui->spinBoxWood->setMaximum(player->getResource(Resource::wood));
    ui->spinBoxClay->setMaximum(player->getResource(Resource::clay));
    ui->spinBoxStone->setMaximum(player->getResource(Resource::stone));
    ui->spinBoxGold->setMaximum(player->getResource(Resource::gold));
}

PayCiv::~PayCiv(){
    delete ui;
}

void PayCiv::on_cancelButton_clicked(){
    m_player = nullptr;
    this->close();
}

int PayCiv::totalSet(){
    int total = 0;
    total += ui->spinBoxWood->value();
    total += ui->spinBoxClay->value();
    total += ui->spinBoxStone->value();
    total += ui->spinBoxGold->value();
    return total;
}

void PayCiv::removeResources(){
    m_player->addResource(Resource::wood, -ui->spinBoxWood->value());
    m_player->addResource(Resource::clay, -ui->spinBoxClay->value());
    m_player->addResource(Resource::stone, -ui->spinBoxStone->value());
    m_player->addResource(Resource::gold, -ui->spinBoxGold->value());
}

void PayCiv::on_acceptButton_clicked(){
    int total = totalSet();
    if(total != m_amount){
        return;
    }
    removeResources();
    m_civ->giveItems(m_player);
    m_player = nullptr;
    m_hasPayed = true;
    this->close();
}