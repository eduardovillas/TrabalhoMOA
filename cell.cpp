#include "cell.h"
#include "board.h"

Cell::Cell(int row, int col, int value, Board *board) :
    m_row(row), m_col(col), m_value(value), m_board(board)
{
    initAdjacentCells();
}

Cell::Cell(const Cell &other)
{
    swap(other);
}

Cell::Cell() :
    m_row(0), m_col(0), m_value(0)
{
    initAdjacentCells();
}

Cell::~Cell()
{
}

Cell &Cell::operator=(const Cell &other)
{
    if (*this == other){
        return *this;
    }

    swap(other);
    return *this;
}

bool Cell::operator==(const Cell &other)
{
    return m_row == other.m_row &&
            m_col == other.m_col &&
            m_value == other.m_value &&
            m_upCell == other.m_upCell &&
            m_dowCell == other.m_dowCell &&
            m_leftCell == other.m_leftCell &&
            m_rightCell == other.m_rightCell;
}

void Cell::swap(const Cell &other)
{
    m_row = other.m_row;
    m_col = other.m_col;
    m_value = other.m_value;
    m_upCell = other.m_upCell;
    m_dowCell = other.m_dowCell;
    m_leftCell = other.m_leftCell;
    m_rightCell = other.m_rightCell;
    m_board = other.m_board;
}

int Cell::getRow()
{
    return m_row;
}

int Cell::getCol()
{
    return m_col;
}

int Cell::getValue() const
{
    return m_value;
}

void Cell::setValue(int value)
{
    m_value = value;
}

void Cell::initAdjacentCells()
{
    m_upCell = 0;
    m_dowCell = 0;
    m_rightCell = 0;
    m_leftCell = 0;
}

void Cell::swapCells(Cell *thisCell, Cell *m_destineCell)
{
    thisCell->m_value = m_destineCell->m_value;
    m_destineCell->m_value = 0;

}

bool Cell::up()
{
    if (!canUp())
        return false;

    swapCells(this, m_upCell);
    return true;
}

bool Cell::canUp() const
{
    if (m_upCell == 0)
        return false;

    if (m_value != 0)
        return false;

    return true;
}

bool Cell::down()
{
    if (!canDown())
        return false;

    swapCells(this, m_dowCell);
    return true;
}

bool Cell::canDown() const
{
    if (m_dowCell == 0)
        return false;

    if (m_value != 0)
        return false;

    return true;
}

bool Cell::left()
{
    if (!canLeft())
        return false;

    swapCells(this, m_leftCell);
    return true;
}

bool Cell::canLeft() const
{
    if (m_leftCell == 0)
        return false;

    if (m_value != 0)
        return false;

    return true;
}

bool Cell::right()
{
    if (!canRight())
        return false;

    swapCells(this, m_rightCell);
    return true;
}

bool Cell::canRight() const
{
    if (m_rightCell == 0)
        return false;

    if (m_value != 0)
        return false;

    return true;
}

Cell *Cell::getLeftCell() const
{
    return m_leftCell;
}

void Cell::setLeftCell(Cell *leftCell)
{
    m_leftCell = leftCell;
}

Cell *Cell::getDowCell() const
{
    return m_dowCell;
}

void Cell::setDowCell(Cell *dowCell)
{
    m_dowCell = dowCell;
}

Cell *Cell::getUpCell() const
{
    return m_upCell;
}

void Cell::setUpCell(Cell *upCell)
{
    m_upCell = upCell;
}

Cell *Cell::getRightCell() const
{
    return m_rightCell;
}

void Cell::setRightCell(Cell *rightCell)
{
    m_rightCell = rightCell;
}

