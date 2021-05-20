#ifndef SHOWCIVREWARD_H
#define SHOWCIVREWARD_H

#include <QDialog>
#include "player.h"

namespace Ui {
class ShowCivReward;
}

class ShowCivReward : public QDialog
{
    Q_OBJECT

public:
    explicit ShowCivReward(std::shared_ptr<Player>player, bool card = false, bool food = false, bool score = false, bool tool = false, bool xtool= false, int resource = 0, int amount = 0, QWidget *parent = nullptr);
    ~ShowCivReward();

private:
    Ui::ShowCivReward *ui;
    const QString resourceToString(Resource resource);
};

#endif // SHOWCIVREWARD_H
