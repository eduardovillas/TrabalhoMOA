#ifndef MOA_RELATIONSHIPBUILDER_H
#define MOA_RELATIONSHIPBUILDER_H

#include "cell.h"
#include "moa_global.h"

class RelationShipBuilder
{
public:
    RelationShipBuilder(Cell arrayBoard[][SIZE_SIDE_BOARD]);
    void buildRelation(Cell *currentCell);
private:
    void buildUpRelationShip(Cell *currentCell, int row, int col);
    void buildDownRelationShip(Cell *currentCell, int row, int col);
    void buildLeftRelationShip(Cell *currentCell, int row, int col);
    void buildRightRelationShip(Cell *currentCell, int row, int col);

    Cell *m_arrayBoard[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD];
};

#endif // MOA_RELATIONSHIPBUILDER_H
