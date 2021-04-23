#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QVBoxLayout>
#include "boardview.h"
#include "workeradd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<Board> board(new Board());
    MainWindow g(board);
    g.show();
    return a.exec();
}
