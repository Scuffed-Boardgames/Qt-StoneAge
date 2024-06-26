// Denzell Mgbokwere 2054872
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonDocument>

MainWindow::MainWindow(const std::shared_ptr<Board> board, QWidget *parent)
    : QMainWindow(parent), m_ui(new Ui::MainWindow), m_boardview(new BoardView(board, this)), m_board(board){

    m_ui->setupUi(this);
    QString text = "Round: " + QString::number(m_board->getRound()+1);
    m_ui->Turn->setText(text);
    QColor red(237, 28, 36);
    m_playerviews.push_back(std::make_shared<PlayerView>(red.darker(200), board->getPlayer(Colour::red)));
    QColor blue(63, 72, 204);
    m_playerviews.push_back(std::make_shared<PlayerView>(blue.darker(200), board->getPlayer(Colour::blue)));
    QColor yellow(255, 242, 0);
    m_playerviews.push_back(std::make_shared<PlayerView>(yellow.darker(200), board->getPlayer(Colour::yellow)));
    QColor green(34, 177, 76);
    m_playerviews.push_back(std::make_shared<PlayerView>(green.darker(200), board->getPlayer(Colour::green)));

    connect(m_board.get(), &Board::roundChanged, this, &MainWindow::updateRound);
    connect(m_boardview.get(), &BoardView::endGame, this, &MainWindow::gameEnded);
    connect(m_boardview.get(), &BoardView::highlight, this, &MainWindow::highlight);
    connect(m_boardview.get(), &BoardView::unHighlight, this, &MainWindow::unHighlight);
    m_ui->quitButton->setVisible(false);
    m_ui->redView->setScene(m_playerviews[0].get());
    m_ui->blueView->setScene(m_playerviews[1].get());
    m_ui->yellowView->setScene(m_playerviews[2].get());
    m_ui->greenView->setScene(m_playerviews[3].get());
    m_ui->BoardView->setScene(m_boardview.get());
    m_ui->Turn->setFont(QFont( "Arial", 25, QFont::Bold));
    m_playerviews[0]->highlight();
}

MainWindow::~MainWindow(){
    delete m_ui;
}

void MainWindow::updateRound(){
    QString text = "Round: " + QString::number(m_board->getRound()+1);
    m_ui->Turn->setText(text);
}


void MainWindow::on_quitButton_clicked(){
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
//    for(std::shared_ptr<PlayerView> player : m_playerviews){
      for(int i = 0; i < 4; ++i){
        m_playerviews[i]->unHighlight();
        m_playerviews[i]->updateText();
    }
    updateRound();
    highlight(m_board->getCurrentPlayer());
    gameUnEnded();
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
    QFile file(":/files/files/cleanSave.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray data = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonObject jsonObject = document.object();
    m_board->load(jsonObject);
    m_board->rerollBuildings();
    m_board->newOpenCivCards();
    for(std::shared_ptr<PlayerView> player : m_playerviews){
        player->unHighlight();
        player->updateText();
    }
    updateRound();
    highlight(m_board->getCurrentPlayer());
    gameUnEnded();
}

void MainWindow::highlight(Colour colour){
    m_playerviews[(int) colour]->highlight();
}

void MainWindow::unHighlight(Colour colour){
    m_playerviews[(int) colour]->unHighlight();
}
void MainWindow::gameUnEnded(){
    m_ui->quitButton->setVisible(false);
    m_ui->stopButton->setVisible(true);
    m_boardview->setSelectable(true);
    for (std::shared_ptr<PlayerView> player : m_playerviews){
        player->unEnd();
    }
}

void MainWindow::gameEnded(){
    for (std::shared_ptr<PlayerView> player : m_playerviews){
        player->unHighlight();
    }
    m_boardview->setSelectable(false);
    int highestScore = 0;
    std::vector<int> highestScorePlayer;
    for (int i = 0; i < (int)m_playerviews.size(); ++i){
        int score = m_playerviews[i]->showScore();
        if(score > highestScore){
            highestScore = score;
            highestScorePlayer.clear();
            highestScorePlayer.push_back(i);
        } else if(score == highestScore) {
            highestScorePlayer.push_back(i);

        }

    }
    std::vector<int> bestPlayer;
    if(highestScorePlayer.size() > 1){
        int highestTieBreak = 0;
        for(int pos : highestScorePlayer){
            int tieBreak = m_playerviews[pos]->showTieBreak();
            if(tieBreak > highestTieBreak){
                bestPlayer.clear();
                highestTieBreak = tieBreak;
                bestPlayer.push_back(pos);
            }else if (tieBreak == highestTieBreak) {
                bestPlayer.push_back(pos);
            }

        }
    } else {
        bestPlayer = highestScorePlayer;
    }
    for(int pos : bestPlayer)
        m_playerviews[pos]->highlight();
}


void MainWindow::on_stopButton_clicked(){
    m_ui->quitButton->setVisible(true);
    m_ui->stopButton->setVisible(false);
    gameEnded();
}
