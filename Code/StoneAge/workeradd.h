#ifndef WORKERADD_H
#define WORKERADD_H

#include <QDialog>
#include "resourceplaceview.h"
#include "buildingview.h"
#include "gather.h"

namespace Ui {
class WorkerAdd;
}

class WorkerAdd : public QDialog
{
    Q_OBJECT

public:
    explicit WorkerAdd(QWidget *parent = nullptr);
    void addToPlace(std::shared_ptr<Place> place, std::shared_ptr<Player> player);
    void setStatic(int amount);
    void setDynamic();
    ~WorkerAdd();

    void addToBuilding(std::shared_ptr<Building> building, std::shared_ptr<Player> player);

private slots:
    void on_okayButton_clicked();
    void on_cancelButton_clicked();

private:
    std::shared_ptr<Building> m_building;
    std::shared_ptr<Player> m_player;
    std::shared_ptr<Place> m_place;
    Ui::WorkerAdd* ui;
};

#endif // WORKERADD_H
