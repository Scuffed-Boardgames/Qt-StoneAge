#ifndef PAYCIV_H
#define PAYCIV_H

#include <QDialog>

namespace Ui {
class PayCiv;
}

class PayCiv : public QDialog
{
    Q_OBJECT

public:
    explicit PayCiv(QWidget *parent = nullptr);
    ~PayCiv();

private:
    Ui::PayCiv *ui;
};

#endif // PAYCIV_H
