#include "board.h"
#include "relationshipbuilder.h"

Board::Board() : emptyCell(0) {
    fillCells();
    buildRelationshipCells();
}

Board::~Board() {
}

int Board::at(int pos) const
{
    int row;
    int col;

    calculeRowCol(pos, &row, &col);

    return at(row,col);
}

int Board::at(int x, int y) const
{
    return m_arrayBoard[x][y].getValue();
}

bool Board::fillValues(int values[][SIZE_SIDE_BOARD])
{
    emptyCell = 0;
    for (int i = 1;i <= SIZE_SIDE_BOARD*SIZE_SIDE_BOARD;++i) {
        int row;
        int col;
        calculeRowCol(i, &row, &col);
        int value = values[row][col];

        Cell *cell = &m_arrayBoard[row][col];

        if (value == 0 ) {
            if (emptyCell != 0)
                return false;
            emptyCell = cell;
        }

        cell->setValue(value);
    }

    return emptyCell != 0;
}

bool Board::up(int pos)
{
    Cell *cell;

    cell = const_cast<Cell *>(getCell(pos));

    return cell->up();
}

bool Board::canUp(int pos) const
{
    return getCell(pos)->canUp();
}

bool Board::canUp(int row, int col) const
{
    return getCell(row, col)->canUp();
}

bool Board::down(int pos)
{
    Cell *cell;

    cell = const_cast<Cell *>(getCell(pos));

    return cell->down();
}

bool Board::canDown(int pos)
{
    return getCell(pos)->canDown();
}

bool Board::canDown(int row, int col)
{
    return getCell(row, col)->canDown();
}

bool Board::left(int pos)
{
    Cell *cell;

    cell = const_cast<Cell *>(getCell(pos));

    return cell->left();
}

bool Board::canleft(int pos)
{
    return getCell(pos)->canLeft();
}

bool Board::canleft(int row, int col)
{
    return getCell(row, col)->canLeft();
}

bool Board::right(int pos)
{
    Cell *cell;

    cell = const_cast<Cell *>(getCell(pos));

    return cell->right();
}

bool Board::canright(int pos)
{
    return getCell(pos)->canRight();
}

bool Board::canright(int row, int col)
{
    return getCell(row, col)->canRight();
}

void Board::calculeRowCol(int pos, int *row, int *col) const
{
    *row = (pos-1)/4;
    *col = ((pos-1)-(*row*4));
}

void Board::buildRelationshipCells()
{
    RelationShipBuilder b(m_arrayBoard);

    for (int i = 1; i <= SIZE_SIDE_BOARD*SIZE_SIDE_BOARD; ++i) {
        int row;
        int col;
        calculeRowCol(i, &row, &col);
        b.buildRelation(&m_arrayBoard[row][col]);
    }
}

void Board::fillCells()
{
    for (int i = 1; i <= SIZE_SIDE_BOARD*SIZE_SIDE_BOARD; ++i) {
        int row;
        int col;
        calculeRowCol(i, &row, &col);
        Cell cell(row, col, 0, this);
        m_arrayBoard[row][col] = cell;
    }
}

const Cell *Board::getCell(int pos) const
{
    int row;
    int col;
    calculeRowCol(pos, &row, &col);

    return getCell(row, col);
}

const Cell *Board::getCell(int row, int col) const
{
    return &m_arrayBoard[row][col];
}

