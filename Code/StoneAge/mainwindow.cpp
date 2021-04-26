#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(const std::shared_ptr<Board> board, QWidget *parent) : QMainWindow(parent), m_ui(new Ui::MainWindow), m_boardview(new BoardView(board, this))
{
    m_ui->setupUi(this);
    QColor red(237, 28, 36);
    m_playerviews.push_back(new PlayerView(red, board->getPlayer(Colour::red)));
    QColor blue(63, 72, 204);
    m_playerviews.push_back(new PlayerView(blue, board->getPlayer(Colour::blue)));
    QColor yellow(255, 242, 0);
    m_playerviews.push_back(new PlayerView(yellow, board->getPlayer(Colour::yellow)));
    QColor green(34, 177, 76);
    m_playerviews.push_back(new PlayerView(green, board->getPlayer(Colour::green)));
    m_ui->redView->setScene(m_playerviews[0]);
    m_ui->blueView->setScene(m_playerviews[1]);
    m_ui->yellowView->setScene(m_playerviews[2]);
    m_ui->greenView->setScene(m_playerviews[3]);
    m_ui->BoardView->setScene(m_boardview);
    QFont font( "Arial", 25, QFont::Bold);
    m_ui->Turn->setFont(font);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}


void MainWindow::on_quitButton_clicked()
{
    this->close();
}
