#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "board.h"
#include "workeradd.h"
#include "otherplaceview.h"
#include "resourceplaceview.h"
#include "civilisationview.h"

class BoardView : public QGraphicsScene
{
    Q_OBJECT

public:
    BoardView(std::shared_ptr<Board> board, QObject* parent = nullptr);

public slots:
    void updateCivCards();
    void newBuild(std::shared_ptr<Building> building, int pos);
    void updateTurn();
    void placementDone();
    void setSelectable(bool isSelectalbe);

signals:
    void highlight(Colour colour);
    void unHighlight(Colour colour);
    void endGame();

private:
    bool m_placementDone;
    std::unique_ptr<BuildingView> m_buildings[4];
    std::unique_ptr<CivilisationView> m_civilisations[4];
    std::shared_ptr<Board> m_board;
    std::shared_ptr<ResourcePlaceView> m_food;
    std::unique_ptr<ResourcePlaceView> m_wood;
    std::unique_ptr<ResourcePlaceView> m_clay;
    std::unique_ptr<ResourcePlaceView> m_stone;
    std::unique_ptr<ResourcePlaceView> m_gold;
    std::unique_ptr<OtherPlaceView> m_field;
    std::unique_ptr<OtherPlaceView> m_hut;
    std::unique_ptr<OtherPlaceView> m_toolshed;

    void gameLoop();
    void updateResources(Colour colour);
    void buildBuildings(Colour colour);
    void civilizeCivilisations(Colour colour);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BOARDVIEW_H
