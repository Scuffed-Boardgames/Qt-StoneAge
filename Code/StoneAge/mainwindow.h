#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"boardview.h"
#include"playerview.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<Board> board, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    BoardView m_boardview;
    std::vector<PlayerView*> m_playerviews;
};
#endif // MAINWINDOW_H
