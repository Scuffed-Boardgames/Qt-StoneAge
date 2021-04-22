#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "board.h"

class BoardView : public QGraphicsScene
{
    Q_OBJECT

public:
    BoardView(std::shared_ptr<Board> board);
    BoardView();
private:
    std::shared_ptr<Board> m_board;
    std::vector<QGraphicsTextItem*> m_huntValues;
    std::vector<QGraphicsTextItem*> m_forestValues;
    std::vector<QGraphicsTextItem*> m_claypitValues;
    std::vector<QGraphicsTextItem*> m_quarryValues;
    std::vector<QGraphicsTextItem*> m_riverValues;
};

#endif // BOARDVIEW_H
