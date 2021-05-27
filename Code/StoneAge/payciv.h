// Bernd Uijtdebroeks 2055267
#ifndef PAYCIV_H
#define PAYCIV_H

#include <QDialog>
#include "player.h"
#include "civilisation.h"

namespace Ui {
class PayCiv;
}

class PayCiv : public QDialog
{
    Q_OBJECT

public:
    explicit PayCiv(std::shared_ptr<Player> player, std::shared_ptr<Civilisation> civCard);
    ~PayCiv();

    bool getHasPayed() const;

private slots:
    void editText();
    void on_acceptButton_clicked();
    void on_cancelButton_clicked();

private:
    int totalSet();
    void removeResources();
    std::shared_ptr<Player> m_player;
    std::shared_ptr<Civilisation> m_civ;
    int m_amount;
    bool m_hasPayed;
    Ui::PayCiv *ui;
};

#endif // PAYCIV_H
