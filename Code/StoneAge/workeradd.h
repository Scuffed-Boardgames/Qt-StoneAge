#ifndef WORKERADD_H
#define WORKERADD_H

#include <QWidget>

namespace Ui {
class workerAdd;
}

class workerAdd : public QWidget
{
    Q_OBJECT

public:
    explicit workerAdd(QWidget *parent = nullptr);
    int getAmount();
    void setFixed(int amount);
    ~workerAdd();

private slots:
    void on_okayButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::workerAdd *ui;
    int m_amount;
};

#endif // WORKERADD_H
