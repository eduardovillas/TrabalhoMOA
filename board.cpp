#include "board.h"

Board::Board() : m_emptyCell(0) {
    createCells();
}

Board::Board(const Board &other)
{
    createCells();
    swap(other);
}

Board &Board::operator=(const Board &other)
{
    createCells();
    swap(other);

    return *this;
}

Board::~Board() {
}

bool Board::fillValues(char values[][SIZE_SIDE_BOARD])
{
    m_emptyCell = 0;
    for (char i = 1;i <= SIZE_SIDE_BOARD*SIZE_SIDE_BOARD;++i) {
        int row;
        int col;
        Cell::calculeRowCol(i, &row, &col);
        char value = values[row][col];

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

char Board::at(int pos) const
{
    int row;
    int col;

    Cell::calculeRowCol(pos, &row, &col);

    return at(row,col);
}

char Board::at(int x, int y) const
{
    return m_arrayBoard[x][y].getValue();
}

bool Board::up()
{
    return m_emptyCell->up();
}

bool Board::canUp() const
{
    return m_emptyCell->canUp();
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

void Board::createCells()
{
    for (char i = 1; i <= SIZE_SIDE_BOARD*SIZE_SIDE_BOARD; ++i) {
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

Cell *Board::getCell(char pos)
{
    int row;
    int col;
    Cell::calculeRowCol(pos, &row, &col);

    return getCell(row, col);
}

Cell *Board::getCell(int row, int col)
{
    return &m_arrayBoard[row][col];
}

char Board::getCellsInPosition() const
{
    return m_cellsInPosition;
}

void Board::setCellsInPosition(char value)
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
    return getCellsInPosition() >= ((SIZE_SIDE_BOARD*SIZE_SIDE_BOARD));
}

void Board::incrementTries()
{
    ++m_tries;
}

unsigned long long Board::getTries()
{
    return m_tries;
}

Cell *Board::getUpCell()
{
    int row = m_emptyCell->getRow();
    int col = m_emptyCell->getCol();

    if (row == 0)
        return 0;

    return &m_arrayBoard[--row][col];
}

Cell *Board::getDownCell()
{
    int row = m_emptyCell->getRow();
    int col = m_emptyCell->getCol();

    if (row == SIZE_SIDE_BOARD-1)
        return 0;

    return &m_arrayBoard[++row][col];
}

Cell *Board::getLeftCell()
{
    int row = m_emptyCell->getRow();
    int col = m_emptyCell->getCol();

    if (col == 0)
        return 0;

    return &m_arrayBoard[row][--col];

}

Cell *Board::getRightCell()
{
    int row = m_emptyCell->getRow();
    int col = m_emptyCell->getCol();

    if (col == SIZE_SIDE_BOARD-1)
        return 0;

    return &m_arrayBoard[row][++col];

}

bool Board::copyCells(const Cell arrayBoard[][SIZE_SIDE_BOARD])
{

    for (int i = 0; i < SIZE_SIDE_BOARD; ++i){
        for (int j = 0; j < SIZE_SIDE_BOARD; ++j) {
            m_arrayBoard[i][j] = arrayBoard[i][j];
            m_arrayBoard[i][i].setBoard(this);
        }
    }

    return true;
}

void Board::swap(const Board &other)
{
    copyCells(other.m_arrayBoard);
    int row;
    int col;

    row = other.m_emptyCell->getRow();
    col = other.m_emptyCell->getCol();

    m_emptyCell = &m_arrayBoard[row][col];
    m_cellsInPosition = other.m_cellsInPosition;
    m_tries = other.m_tries;

}


