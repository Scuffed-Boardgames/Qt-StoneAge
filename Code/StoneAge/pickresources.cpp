#include "pickresources.h"
#include "ui_pickresources.h"
#include "resources.h"

PickResources::PickResources(std::shared_ptr<Player> player) :
    QDialog(nullptr), ui(new Ui::PickResources), m_player(player)
{
    ui->setupUi(this);
    this->setWindowTitle(m_player->getString());

}

PickResources::~PickResources(){
    delete ui;
}


void PickResources::on_okayButton_clicked(){
    m_player->addResource((Resource)(ui->choise1->currentIndex() + 3), 1);
    m_player->addResource((Resource)(ui->choise2->currentIndex() + 3), 1);
    m_player = nullptr;
    this->close();
}
