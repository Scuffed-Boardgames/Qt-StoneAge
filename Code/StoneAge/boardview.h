#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "board.h"
#include "workeradd.h"

class BoardView : public QGraphicsScene
{
    Q_OBJECT

public:
    BoardView(std::shared_ptr<Board> board, QObject* parent = nullptr);
    BoardView();
private:
    Colour m_activeColour;
//    QGraphicsRectItem* m_test;
    workerAdd* m_workeradd;
    std::shared_ptr<Board> m_board;
//    std::vector<QGraphicsTextItem*> m_huntValues;
//    std::vector<QGraphicsTextItem*> m_forestValues;
//    std::vector<QGraphicsTextItem*> m_claypitValues;
//    std::vector<QGraphicsTextItem*> m_quarryValues;
//    std::vector<QGraphicsTextItem*> m_riverValues;
    QGraphicsRectItem* m_field;
    QGraphicsRectItem* m_hut;
    QGraphicsRectItem* m_toolshed;
//    std::vector<QBrush> m_brushes;
    std::unique_ptr<placeView> m_food;
//    placeView* m_food;
    std::unique_ptr<placeView> m_wood;
    std::unique_ptr<placeView> m_clay;
    std::unique_ptr<placeView> m_stone;
    std::unique_ptr<placeView> m_gold;
//    void makePlace(QColor colour, QString name, int moveByX, std::vector<QGraphicsTextItem*>* values);
    QGraphicsRectItem* makeSmallPlace(QColor colour, int moveByX,int textMoveX, QString name);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BOARDVIEW_H
