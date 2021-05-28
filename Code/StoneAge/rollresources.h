// Denzell Mgbokwere 2054872
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
    ~RollResources();

    int getGain(); // Returns the amount of resources gained

private slots:
    void on_pushButton_clicked();
    void on_Tool1Button_clicked();
    void on_Tool2Button_clicked();
    void on_Tool3Button_clicked();

    void on_tempTool3Button_clicked();

    void on_tempTool2Button_clicked();

    void on_tempTool1Button_clicked();

private:
    void tempTools(std::vector<int> tools);
    const QString resourceToString(Resource resource);

    Ui::RollResources *ui;
    int m_roll;
    int m_gain;
    Resource m_resource;
    QString m_text;
    std::shared_ptr<Player> m_player;
};

#endif // ROLLRESOURCES_H
