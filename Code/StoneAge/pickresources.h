#ifndef PICKRESOURCES_H
#define PICKRESOURCES_H

#include <QDialog>
#include "player.h"

namespace Ui {
class PickResources;
}

class PickResources : public QDialog
{
    Q_OBJECT

public:
    explicit PickResources(std::shared_ptr<Player> player);
    ~PickResources();

private slots:
      void on_okayButton_clicked();
//    void capButtons();

private:
    Ui::PickResources *ui;
    int totalSet();
    void addResources();

    std::shared_ptr<Player> m_player;
};

#endif // PICKRESOURCES_H
