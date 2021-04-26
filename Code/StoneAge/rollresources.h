#ifndef ROLLRESOURCES_H
#define ROLLRESOURCES_H

#include <QWidget>
#include "player.h"

namespace Ui {
class RollResources;
}

class RollResources : public QWidget
{
    Q_OBJECT

public:
    explicit RollResources(int workerAmount, Resource resource, QString text, QWidget *parent = nullptr);
    int getGain(); //returns the amount of resources gained
    ~RollResources();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RollResources *ui;
    int m_gain;
};

#endif // ROLLRESOURCES_H
