#ifndef ROLLRECOURSES_H
#define ROLLRECOURSES_H

#include <QWidget>
#include "player.h"

namespace Ui {
class RollRecourses;
}

class RollRecourses : public QWidget
{
    Q_OBJECT

public:
    explicit RollRecourses(int workerAmount, Recourse recourse, QString text, QWidget *parent = nullptr);
    int getGain();
    ~RollRecourses();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RollRecourses *ui;
    QString recourseToText(Recourse recourse);
    int m_gain;
};

#endif // ROLLRECOURSES_H
