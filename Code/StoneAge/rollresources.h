#ifndef ROLLRESOURCES_H
#define ROLLRESOURCES_H

#include <QDialog>
#include "player.h"

namespace Ui {
class RollResources;
}

class RollResources : public QDialog
{
    Q_OBJECT

public:
    explicit RollResources(int workerAmount, Resource resource, std::shared_ptr<Player> player, QWidget *parent = nullptr);
    int getGain(); //returns the amount of resources gained
    QString colourToString(Colour colour);
    ~RollResources();

private slots:
    void on_pushButton_clicked();

    void on_Tool1Button_clicked();

    void on_Tool2Button_clicked();

    void on_Tool3Button_clicked();

private:
    const QString resourceToString(Resource resource);
    Ui::RollResources *ui;
    int m_roll;
    int m_gain;
    Resource m_resource;
    QString m_text;
    std::shared_ptr<Player> m_player;
};

#endif // ROLLRESOURCES_H
