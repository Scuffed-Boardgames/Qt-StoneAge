// Denzell Mgbokwere 2054872
#ifndef WORKERADD_H
#define WORKERADD_H

#include <QDialog>
#include "resourceplaceview.h"
#include "civilisation.h"
#include "buildingview.h"


namespace Ui {
class WorkerAdd;
}

class WorkerAdd : public QDialog
{
    Q_OBJECT

public:
    explicit WorkerAdd(QWidget *parent = nullptr);
    ~WorkerAdd();

    void addToPlace(std::shared_ptr<Place> place, std::shared_ptr<Player> player);

    void setStatic(int amount);
    void setDynamic();

    void addToBuilding(std::shared_ptr<Building> building, std::shared_ptr<Player> player);

    void addToCiv(std::shared_ptr<Civilisation> civ, std::shared_ptr<Player> player);
private slots:
    void on_okayButton_clicked();
    void on_cancelButton_clicked();

private:
    std::shared_ptr<Building> m_building;
    std::shared_ptr<Player> m_player;
    std::shared_ptr<Place> m_place;
    std::shared_ptr<Civilisation> m_civilisation;
    Ui::WorkerAdd* ui;
};

#endif // WORKERADD_H
