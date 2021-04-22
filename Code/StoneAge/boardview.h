#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "board.h"

class BoardView : public QGraphicsScene
{
    Q_OBJECT

public:
    BoardView(qreal x, qreal y, qreal width, qreal height, std::shared_ptr<Board> board, QObject *parent = nullptr);
    BoardView();
private:
    std::shared_ptr<Board> m_board;
};

#endif // BOARDVIEW_H
