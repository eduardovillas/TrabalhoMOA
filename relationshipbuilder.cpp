#include "relationshipbuilder.h"
#include "moa_global.h"

RelationShipBuilder::RelationShipBuilder(Cell arrayBoard[][4])
{

    for (int i = 0;i < SIZE_SIDE_BOARD*SIZE_SIDE_BOARD; ++i) {
        Cell *cur = &arrayBoard[0][i];
        int row = cur->getRow();
        int col = cur->getCol();
        m_arrayBoard[row][col] = cur;
    }
}

void RelationShipBuilder::buildRelation(Cell *currentCell)
{
    int row = currentCell->getRow();
    int col = currentCell->getCol();
    buildUpRelationShip(currentCell, row, col);
    buildDownRelationShip(currentCell, row, col);
    buildLeftRelationShip(currentCell, row, col);
    buildRightRelationShip(currentCell, row, col);

}

void RelationShipBuilder::buildUpRelationShip(Cell *currentCell, int row, int col)
{
    if (row == 0)
        return;

    currentCell->setUpCell(m_arrayBoard[--row][col]);
}

void RelationShipBuilder::buildDownRelationShip(Cell *currentCell, int row, int col)
{
    if (row == SIZE_SIDE_BOARD-1)
        return;

    currentCell->setDowCell(m_arrayBoard[++row][col]);
}

void RelationShipBuilder::buildLeftRelationShip(Cell *currentCell, int row, int col)
{
    if (col == 0)
        return;

    currentCell->setLeftCell(m_arrayBoard[row][--col]);
}

void RelationShipBuilder::buildRightRelationShip(Cell *currentCell, int row, int col)
{
    if (col == SIZE_SIDE_BOARD-1)
        return;

    currentCell->setRightCell(m_arrayBoard[row][++col]);
}

