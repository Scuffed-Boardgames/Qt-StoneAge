#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(std::shared_ptr<Board> board, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), m_boardview(board)
{
    ui->setupUi(this);
    QColor red(237, 28, 36);
    m_playerviews.push_back(new PlayerView(red, board->getPlayer(0)));
    QColor blue(63, 72, 204);
    m_playerviews.push_back(new PlayerView(blue, board->getPlayer(1)));
    QColor yellow(255, 242, 0);
    m_playerviews.push_back(new PlayerView(yellow, board->getPlayer(2)));
    QColor green(34, 177, 76);
    m_playerviews.push_back(new PlayerView(green, board->getPlayer(3)));
    ui->redView->setScene(m_playerviews[0]);
    ui->blueView->setScene(m_playerviews[1]);
    ui->yellowView->setScene(m_playerviews[2]);
    ui->greenView->setScene(m_playerviews[3]);
    ui->BoardView->setScene(&m_boardview);
    QFont font( "Arial", 25, QFont::Bold);
    ui->Turn->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

