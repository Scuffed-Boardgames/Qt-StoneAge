#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QVBoxLayout>
#include "boardview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<Board> board(new Board());
    BoardView* scene = new BoardView(board);
    QGraphicsView* view = new QGraphicsView((QGraphicsScene*)scene);
    view->setScene(scene);
    view->show();
    return a.exec();
}
