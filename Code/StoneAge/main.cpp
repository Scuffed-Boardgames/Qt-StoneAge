// Denzell Mgbokwere 2054872
#include "board.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    std::shared_ptr<Board> board(new Board());
    std::shared_ptr<MainWindow> g(new MainWindow(board));
    g->showFullScreen();
    return a.exec();
}
