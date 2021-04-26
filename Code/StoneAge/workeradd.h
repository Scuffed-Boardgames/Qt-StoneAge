#ifndef WORKERADD_H
#define WORKERADD_H

#include <QWidget>
#include "resourceplaceview.h"

namespace Ui {
class WorkerAdd;
}

class WorkerAdd : public QWidget
{
    Q_OBJECT

public:
    explicit WorkerAdd(QWidget *parent = nullptr);
    void addToPlace(ResourcePlaceView* place, Colour colour);
    void setStatic(int amount);
    void setDynamic();
    ~WorkerAdd();

private slots:
    void on_okayButton_clicked();

    void on_cancelButton_clicked();

private:
    Colour m_colour;
    ResourcePlaceView* m_place;
    Ui::WorkerAdd* ui;
};

#endif // WORKERADD_H
