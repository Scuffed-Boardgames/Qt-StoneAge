// Bernd Uijtdebroeks 2055267
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

private:
    Ui::PickResources *ui;
    std::shared_ptr<Player> m_player;
};

#endif // PICKRESOURCES_H
