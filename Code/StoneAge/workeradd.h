#ifndef WORKERADD_H
#define WORKERADD_H

#include <QWidget>
#include <placeview.h>

namespace Ui {
class WorkerAdd;
}

class WorkerAdd : public QWidget
{
    Q_OBJECT

public:
    explicit WorkerAdd(QWidget *parent = nullptr);
    void addToPlace(PlaceView* place, Colour colour);
    void setFixed(int amount);
    ~WorkerAdd();

private slots:
    void on_okayButton_clicked();

    void on_cancelButton_clicked();

private:
    Colour m_colour;
    PlaceView* m_place;
    Ui::WorkerAdd* ui;
};

#endif // WORKERADD_H
