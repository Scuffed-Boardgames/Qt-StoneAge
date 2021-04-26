#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "board.h"
#include "workeradd.h"
#include "otherplaceview.h"
#include "resourceplaceview.h"

class BoardView : public QGraphicsScene
{
    Q_OBJECT

public:
    BoardView(std::shared_ptr<Board> board, QObject* parent = nullptr);
    BoardView();
private:
    Colour m_activeColour;
    std::shared_ptr<WorkerAdd> m_workeradd;
    std::shared_ptr<Board> m_board;
    std::shared_ptr<ResourcePlaceView> m_food;
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
