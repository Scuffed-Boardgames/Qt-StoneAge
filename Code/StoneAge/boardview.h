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
public slots:
    void newBuild(std::shared_ptr<Building> building, int pos);
    void updateTurn();
    void startPayout();
private:
    std::unique_ptr<BuildingView> m_buildings[4];
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
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setSelectable(bool isSelectalbe);
};

#endif // BOARDVIEW_H
