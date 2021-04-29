#include "workeradd.h"
#include "ui_workeradd.h"

WorkerAdd::WorkerAdd(QWidget *parent)
    : QDialog(parent), m_building(nullptr), m_place(nullptr), ui(new Ui::WorkerAdd)
{
    ui->setupUi(this);
}

void WorkerAdd::addToPlace(std::shared_ptr<Place> place, std::shared_ptr<Player> player){
    m_place = place;
    m_player = player;
    this->setWindowTitle(colourToString(player->getColour()));

    std::shared_ptr<Gather> gather = std::dynamic_pointer_cast<Gather>(m_place);
    if(gather){
        int freeSpace = gather->getMaxWorkers() - m_place->totalWorkers();
        int placable = std::min(freeSpace, m_player->getFreeWorkers());
        ui->amount->setMaximum(placable);
        ui->okayButton->setDisabled(placable == 0);
    }
}

void WorkerAdd::addToBuilding(Building* building, std::shared_ptr<Player> player){
    m_building = building;
    m_player = player;
}

WorkerAdd::~WorkerAdd()
{
    delete ui;
}

void WorkerAdd::on_okayButton_clicked(){
    if(m_place)
        m_place->addWorker(m_player, ui->amount->value());
    if(m_building)
        m_building->addWorker(m_player);
    ui->amount->setValue(1);
    m_place = nullptr;
    m_building = nullptr;
    this->close();
}

void WorkerAdd::on_cancelButton_clicked(){
    ui->amount->setValue(1);
    m_place = nullptr;
    ui->okayButton->setEnabled(true);
    this->close();
}

QString WorkerAdd::colourToString(Colour colour)
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

void WorkerAdd::setStatic(const int amount){
    ui->amount->setValue(amount);
    ui->amount->setVisible(false);
    ui->label->setText("Placing " +QString::number(amount)+" workers on this space");
}

void WorkerAdd::setDynamic()
{
    ui->amount->setValue(1);
    ui->amount->setVisible(true);
    ui->label->setText("How many workers do you want to add?");

}
