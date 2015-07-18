#include "board.h"
#include "relationshipbuilder.h"

Board::Board() : m_emptyCell(0) {
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
    m_emptyCell = 0;
    for (int i = 1;i <= SIZE_SIDE_BOARD*SIZE_SIDE_BOARD;++i) {
        int row;
        int col;
        calculeRowCol(i, &row, &col);
        int value = values[row][col];

        Cell *cell = &m_arrayBoard[row][col];

        if (value == 0 ) {
            if (m_emptyCell != 0)
                return false;
            m_emptyCell = cell;
        }
        cell->setValue(value);
    }

    return m_emptyCell != 0;
}

bool Board::up()
{
    return m_emptyCell->up();
}

bool Board::canUp() const
{
    return m_emptyCell;
}

bool Board::down()
{
    return m_emptyCell->down();
}

bool Board::canDown()
{
    return m_emptyCell->canDown();
}

bool Board::left()
{
    return m_emptyCell->left();
}

bool Board::canleft()
{
    return m_emptyCell->canLeft();
}

bool Board::right()
{
    return m_emptyCell->right();
}

bool Board::canright()
{
    return m_emptyCell->canRight();
}

void Board::setEmptyCell(Cell *cell)
{
    m_emptyCell = cell;
}

Cell *Board::getEmptyCell()
{
    return m_emptyCell;
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

