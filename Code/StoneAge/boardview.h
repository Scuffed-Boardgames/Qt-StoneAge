#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "board.h"
#include "workeradd.h"
#include "otherplaceview.h"

class BoardView : public QGraphicsScene
{
    Q_OBJECT

public:
    BoardView(std::shared_ptr<Board> board, QObject* parent = nullptr);
    BoardView();
private:
    Colour m_activeColour;
//    QGraphicsRectItem* m_test;
    std::unique_ptr<WorkerAdd> m_workeradd;
//    WorkerAdd* m_workeradd;
    std::shared_ptr<Board> m_board;
//    std::vector<QGraphicsTextItem*> m_huntValues;
//    std::vector<QGraphicsTextItem*> m_forestValues;
//    std::vector<QGraphicsTextItem*> m_claypitValues;
//    std::vector<QGraphicsTextItem*> m_quarryValues;
//    std::vector<QGraphicsTextItem*> m_riverValues;
//    QGraphicsRectItem* m_field;
//    QGraphicsRectItem* m_hut;
//    QGraphicsRectItem* m_toolshed;
//    std::vector<QBrush> m_brushes;
    std::unique_ptr<ResourcePlaceView> m_food;
    std::unique_ptr<ResourcePlaceView> m_wood;
    std::unique_ptr<ResourcePlaceView> m_clay;
    std::unique_ptr<ResourcePlaceView> m_stone;
    std::unique_ptr<ResourcePlaceView> m_gold;
    std::unique_ptr<OtherPlaceView> m_field;
    std::unique_ptr<OtherPlaceView> m_hut;
    std::unique_ptr<OtherPlaceView> m_toolshed;
    QGraphicsRectItem* makeSmallPlace(QColor colour, int moveByX,int textMoveX, QString name);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BOARDVIEW_H
