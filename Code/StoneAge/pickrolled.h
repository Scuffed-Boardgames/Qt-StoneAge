#ifndef PICKROLLED_H
#define PICKROLLED_H

#include <QDialog>

namespace Ui {
class PickRolled;
}

class PickRolled : public QDialog
{
    Q_OBJECT

public:
    explicit PickRolled(QWidget *parent = nullptr);
    ~PickRolled();

private:
    Ui::PickRolled *ui;
};

#endif // PICKROLLED_H
