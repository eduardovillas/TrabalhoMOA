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

    Cell::calculeRowCol(pos, &row, &col);

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
        Cell::calculeRowCol(i, &row, &col);
        int value = values[row][col];

        Cell *cell = &m_arrayBoard[row][col];

        if (value == 0 ) {
            if (m_emptyCell != 0)
                return false;
            m_emptyCell = cell;
        }
        cell->setValue(value);
    }
    m_tries = 0;
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

void Board::buildRelationshipCells()
{
    RelationShipBuilder b(m_arrayBoard);

    for (int i = 1; i <= SIZE_SIDE_BOARD*SIZE_SIDE_BOARD; ++i) {
        int row;
        int col;
        Cell::calculeRowCol(i, &row, &col);
        b.buildRelation(&m_arrayBoard[row][col]);
    }
}

void Board::fillCells()
{
    for (int i = 1; i <= SIZE_SIDE_BOARD*SIZE_SIDE_BOARD; ++i) {
        int row;
        int col;
        Cell::calculeRowCol(i, &row, &col);
        int value;
        Cell::calculeExpectedValue(row, col, &value);

        Cell cell(row, col, value, this);
        m_arrayBoard[row][col] = cell;
    }
    setCellsInPosition(SIZE_SIDE_BOARD*SIZE_SIDE_BOARD);
}

const Cell *Board::getCell(int pos) const
{
    int row;
    int col;
    Cell::calculeRowCol(pos, &row, &col);

    return getCell(row, col);
}

const Cell *Board::getCell(int row, int col) const
{
    return &m_arrayBoard[row][col];
}
int Board::getCellsInPosition() const
{
    return m_cellsInPosition;
}

void Board::setCellsInPosition(int value)
{
    m_cellsInPosition = value;
}

void Board::incrementCellsInPosition()
{
    ++m_cellsInPosition;
}

void Board::decrementCellsInPosition()
{
    --m_cellsInPosition;
}

bool Board::winGame()
{
    return getCellsInPosition() >= ((SIZE_SIDE_BOARD*SIZE_SIDE_BOARD)-1);
}

void Board::incrementTries()
{
    ++m_tries;
}

unsigned long long Board::getTries()
{
    return m_tries;
}


