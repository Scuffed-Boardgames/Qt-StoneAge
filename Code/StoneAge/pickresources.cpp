#include "pickresources.h"
#include "ui_pickresources.h"
#include "resources.h"

PickResources::PickResources(std::shared_ptr<Player> player) :
    QDialog(nullptr), ui(new Ui::PickResources), m_player(player)
{
    ui->setupUi(this);
    this->setWindowTitle(m_player->getString());
    connect(ui->spinBoxWood, &QSpinBox::valueChanged, this, &PickResources::capButtons);
    connect(ui->spinBoxClay, &QSpinBox::valueChanged, this, &PickResources::capButtons);
    connect(ui->spinBoxStone, &QSpinBox::valueChanged, this, &PickResources::capButtons);
    connect(ui->spinBoxGold, &QSpinBox::valueChanged, this, &PickResources::capButtons);
    ui->spinBoxWood->setMaximum(2);
    ui->spinBoxClay->setMaximum(2);
    ui->spinBoxStone->setMaximum(2);
    ui->spinBoxGold->setMaximum(2);
}

void PickResources::capButtons(){
    int total = totalSet();
    int needed = 2 - total;

    ui->spinBoxWood->setMaximum(std::min(m_player->getResource(Resource::wood), ui->spinBoxWood->value() + needed));
    ui->spinBoxClay->setMaximum(std::min(m_player->getResource(Resource::clay), ui->spinBoxWood->value() + needed));
    ui->spinBoxStone->setMaximum(std::min(m_player->getResource(Resource::stone), ui->spinBoxWood->value() + needed));
    ui->spinBoxGold->setMaximum(std::min(m_player->getResource(Resource::gold), ui->spinBoxWood->value() + needed));

    ui->okayButton->setEnabled(needed == 0);
}

PickResources::~PickResources()
{
    delete ui;
}

int PickResources::totalSet(){
    int total = 0;
    total += ui->spinBoxWood->value();
    total += ui->spinBoxClay->value();
    total += ui->spinBoxStone->value();
    total += ui->spinBoxGold->value();
    return total;
}

void PickResources::addResources(){
    m_player->addResource(Resource::wood, ui->spinBoxWood->value());
    m_player->addResource(Resource::clay, ui->spinBoxClay->value());
    m_player->addResource(Resource::stone, ui->spinBoxStone->value());
    m_player->addResource(Resource::gold, ui->spinBoxGold->value());
}

void PickResources::on_okayButton_clicked(){
    int total = totalSet();
    if(total != 2){
        return;
    }
    addResources();
    m_player = nullptr;
    this->close();
}
