// Bernd Uijtdebroeks 2055267
#include "payciv.h"
#include "ui_payciv.h"

PayCiv::PayCiv(std::shared_ptr<Player> player, std::shared_ptr<Civilisation> civCard)
    : QDialog(nullptr), m_player{player}, m_civ{civCard}, m_amount{m_civ->getCost()}, m_hasPayed{false}, ui(new Ui::PayCiv){

    ui->setupUi(this);
    this->setWindowTitle(player->getString());
    ui->payLabel->setText("You have to pay " + QString::number(m_amount) + " items for this card");
    connect(ui->spinBoxWood, &QSpinBox::valueChanged, this, &PayCiv::editText);
    connect(ui->spinBoxClay, &QSpinBox::valueChanged, this, &PayCiv::editText);
    connect(ui->spinBoxStone, &QSpinBox::valueChanged, this, &PayCiv::editText);
    connect(ui->spinBoxGold, &QSpinBox::valueChanged, this, &PayCiv::editText);
    ui->acceptButton->setEnabled(false);
}

PayCiv::~PayCiv(){
    delete ui;
}

void PayCiv::on_cancelButton_clicked(){
    m_civ->reset();
    m_player = nullptr;
    this->close();
}

void PayCiv::editText(){
    int reqAmount = m_amount - totalSet();
    ui->payLabel->setText("You still have to pay " + QString::number(reqAmount) + " items for this card");
    ui->spinBoxWood->setMaximum(std::min(m_player->getResource(Resource::wood), ui->spinBoxWood->value() + reqAmount));
    ui->spinBoxClay->setMaximum(std::min(m_player->getResource(Resource::clay), ui->spinBoxClay->value() + reqAmount));
    ui->spinBoxStone->setMaximum(std::min(m_player->getResource(Resource::stone), ui->spinBoxStone->value() + reqAmount));
    ui->spinBoxGold->setMaximum(std::min(m_player->getResource(Resource::gold), ui->spinBoxGold->value() + reqAmount));
    ui->acceptButton->setEnabled(reqAmount == 0);
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

bool PayCiv::getHasPayed() const
{
    return m_hasPayed;
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
