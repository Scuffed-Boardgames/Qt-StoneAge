#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "boardview.h"
#include "playerview.h"
#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<Board> board, QWidget *parent = nullptr);// constructor
    ~MainWindow();

public slots:
    void highlight(Colour colour);
    void unHighlight(Colour colour);
    void gameEnded();

private slots:
    void updateRound();
    void on_quitButton_clicked();
    void on_loadButton_clicked();
    void on_saveButton_clicked();
    void on_newGameButton_clicked();

private:
    Ui::MainWindow *m_ui;
    std::unique_ptr<BoardView> m_boardview;
    std::vector<std::shared_ptr<PlayerView>> m_playerviews;
    const std::shared_ptr<Board> m_board;
    QFileDialog* m_fileDialog;
};
#endif // MAINWINDOW_H
