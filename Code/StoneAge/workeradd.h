#ifndef WORKERADD_H
#define WORKERADD_H

#include <QWidget>
#include <placeview.h>

namespace Ui {
class workerAdd;
}

class workerAdd : public QWidget
{
    Q_OBJECT

public:
    explicit workerAdd(QWidget *parent = nullptr);
    void addToPlace(placeView* place, Colour colour);
    void setFixed(int amount);
    ~workerAdd();

private slots:
    void on_okayButton_clicked();

    void on_cancelButton_clicked();

private:
    Colour m_colour;
    placeView *m_place;
    Ui::workerAdd *ui;
};

#endif // WORKERADD_H
