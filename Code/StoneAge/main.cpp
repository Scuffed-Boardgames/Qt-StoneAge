#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QVBoxLayout>
#include "boardview.h"
#include "workeradd.h"
#include "rollresources.h"
#include <ctime>



int main(int argc, char *argv[])
{
    srand(time(0));
    QApplication a(argc, argv);
    std::shared_ptr<Board> board(new Board());
    std::shared_ptr<MainWindow> g(new MainWindow(board));
    g->showFullScreen();
    return a.exec();
}
