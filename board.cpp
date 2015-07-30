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

bool Board::operator<(const Board &other)
{
    return m_cellsNotInPosition + m_moviments < other.m_cellsNotInPosition + other.m_moviments;
}

bool Board::operator>(const Board &other)
{
    return m_cellsNotInPosition + m_moviments > other.m_cellsNotInPosition + other.m_moviments;
}

Board::~Board()
{
    m_key.clear();
}

bool Board::fillValues(char values[][SIZE_SIDE_BOARD])
{
    m_emptyCell = 0;

    for (int row = 0; row < SIZE_SIDE_BOARD; ++row) {
        for (int col = 0; col < SIZE_SIDE_BOARD; ++col) {
            char value = values[row][col];
            Cell *cell = &m_arrayBoard[row][col];

            if (value == 0 ) {
                if (m_emptyCell != 0)
                    return false;
                m_emptyCell = cell;
            }

            cell->setValue(value);
        }
    }
    recalculeKey();
    m_moviments = 0;
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
    m_key.clear();
    for (int row =0 ; row < SIZE_SIDE_BOARD; ++row) {
        for (int col = 0; col < SIZE_SIDE_BOARD; ++col) {

            int expectedValue;
            Cell::calculeExpectedValue(row, col, &expectedValue);
            Cell cell(row, col, expectedValue, this);
            m_arrayBoard[row][col] = cell;
            m_key.append(std::to_string(cell.getValue()));
            m_key.append(" ");

        }
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
unsigned long long Board::getMoviments() const
{
    return m_moviments;
}

void Board::setMoviments(unsigned long long moviments)
{
    m_moviments = moviments;
}


char Board::getCellsInPosition() const
{
    return m_cellsInPosition;
}

void Board::setCellsInPosition(unsigned long long int value)
{
    m_cellsInPosition = value;
    m_cellsNotInPosition = m_cellsInPosition - 16;
}

void Board::incrementCellsInPosition()
{
    ++m_cellsInPosition;
    --m_cellsNotInPosition;
}

void Board::decrementCellsInPosition()
{
    --m_cellsInPosition;
    ++m_cellsNotInPosition;
}

bool Board::winGame()
{
    return getCellsInPosition() >= ((SIZE_SIDE_BOARD*SIZE_SIDE_BOARD));
}

void Board::incrementTries()
{
    ++m_moviments;
}

unsigned long long Board::getTries()
{
    return m_moviments;
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

std::string Board::getKey()
{
    return m_key;
}

void Board::recalculeKey()
{
    m_key.clear();
    for (int row = 0; row < SIZE_SIDE_BOARD; ++row){
        for (int col = 0; col < SIZE_SIDE_BOARD; ++col) {
            m_key.append(std::to_string(m_arrayBoard[row][col].getValue()));
            m_key.append(" ");
        }
    }

}

bool Board::copyCells(const Cell arrayBoard[][SIZE_SIDE_BOARD])
{

    m_key.clear();
    for (int row = 0; row < SIZE_SIDE_BOARD; ++row){
        for (int col = 0; col < SIZE_SIDE_BOARD; ++col) {
            m_arrayBoard[row][col] = arrayBoard[row][col];
            m_arrayBoard[row][col].setBoard(this);
            m_key += std::to_string(m_arrayBoard[row][col].getValue()) + " ";
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
    m_cellsNotInPosition = other.m_cellsNotInPosition;
    m_moviments = other.m_moviments;
    m_key.clear();
    m_key.append(m_key);

}



