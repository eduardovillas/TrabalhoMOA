#ifndef MOA_RELATIONSHIPBUILDER_H
#define MOA_RELATIONSHIPBUILDER_H

#include "cell.h"

class RelationShipBuilder
{
public:
    RelationShipBuilder(Cell arrayBoard[][4]);
    void buildRelation(Cell *currentCell);
private:
    void buildUpRelationShip(Cell *currentCell, int row, int col);
    void buildDownRelationShip(Cell *currentCell, int row, int col);
    void buildLeftRelationShip(Cell *currentCell, int row, int col);
    void buildRightRelationShip(Cell *currentCell, int row, int col);

    Cell *m_arrayBoard[4][4];
};

#endif // MOA_RELATIONSHIPBUILDER_H
