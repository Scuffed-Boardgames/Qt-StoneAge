#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <Qdir>

MainWindow::MainWindow(const std::shared_ptr<Board> board, QWidget *parent)
    : QMainWindow(parent), m_ui(new Ui::MainWindow), m_boardview(new BoardView(board, this)), m_board(board), m_fileDialog(new QFileDialog(this))
{
    m_ui->setupUi(this);
    QColor red(237, 28, 36);
    m_playerviews.push_back(std::make_shared<PlayerView>(red, board->getPlayer(Colour::red)));
    QColor blue(63, 72, 204);
    m_playerviews.push_back(std::make_shared<PlayerView>(blue, board->getPlayer(Colour::blue)));
    QColor yellow(255, 242, 0);
    m_playerviews.push_back(std::make_shared<PlayerView>(yellow, board->getPlayer(Colour::yellow)));
    QColor green(34, 177, 76);
    m_playerviews.push_back(std::make_shared<PlayerView>(green, board->getPlayer(Colour::green)));

    for(int i = 0; i<4 ; ++i){
        connect(board->getGather(Resource::food), &Place::resourcesChanged, m_playerviews[i].get(), &PlayerView::updateText);
    }

    m_ui->redView->setScene(m_playerviews[0].get());
    m_ui->blueView->setScene(m_playerviews[1].get());
    m_ui->yellowView->setScene(m_playerviews[2].get());
    m_ui->greenView->setScene(m_playerviews[3].get());
    m_ui->BoardView->setScene(m_boardview.get());
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

void MainWindow::on_loadButton_clicked(){
    QString filePath = QFileDialog::getOpenFileName(this, "Load", ":/save/saves/", "JSON Files (*.json)");
    QFile file(filePath);
    if(file.size() == 0)
        return;
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray data = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonObject jsonObject = document.object();
    m_board->load(jsonObject);
}

void MainWindow::on_saveButton_clicked(){
     QString filePath = QFileDialog::getSaveFileName(this, "Save", ":/save/saves/", "JSON Files (*.json)");
     QFile file(filePath);
     file.open(QIODevice::ReadWrite);
     QJsonDocument jsonDocument;
     QJsonObject jsonObject = m_board->save();
     jsonDocument.setObject(jsonObject);
     file.resize(0);
     file.write(jsonDocument.toJson());
     file.close();
}

void MainWindow::on_newGameButton_clicked(){
     QFile file(":/save/saves/clean.json");
     file.open(QIODevice::ReadOnly | QIODevice::Text);
     QByteArray data = file.readAll();
     file.close();
     QJsonDocument document = QJsonDocument::fromJson(data);
     QJsonObject jsonObject = document.object();
     m_board->load(jsonObject);

}
