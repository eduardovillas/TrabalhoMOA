#include "cell.h"
#include "board.h"
#include <iostream>
#include "moa_global.h"

static int s_MatrixExpectedValues[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD] = {{1,2,3,4},{12,13,14,5},{11,0,15,6},{10,9,8,7}};

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
    int expectedValue;
    Cell::calculeExpectedValue(m_row, m_col, &expectedValue);

    atualizeStatusGame(m_value, value, expectedValue);

    m_value = value;
}

void Cell::initAdjacentCells()
{
    m_upCell = 0;
    m_dowCell = 0;
    m_rightCell = 0;
    m_leftCell = 0;
}

void Cell::swapCellsValues(Cell *thisCell, Cell *m_destineCell)
{

    int tempValueThisCell;
    int tempValueDestineCell;

    Cell tempThisCell;
    Cell tempDestineCell;

    tempThisCell = *thisCell;
    tempDestineCell = *m_destineCell;

    tempValueThisCell = thisCell->m_value;
    tempValueDestineCell = m_destineCell->m_value;

    thisCell->m_value = tempValueDestineCell;
    m_destineCell->m_value = tempValueThisCell;


    if (tempThisCell.valueInPosition() && !thisCell->valueInPosition()) {
        m_board->decrementCellsInPosition();
    } else if (!tempDestineCell.valueInPosition() && thisCell->valueInPosition()) {
        m_board->incrementCellsInPosition();
    }

    if (tempDestineCell.valueInPosition() && !m_destineCell->valueInPosition()) {
        m_board->decrementCellsInPosition();
    } else if (!tempDestineCell.valueInPosition() && m_destineCell->valueInPosition() ) {
        m_board->incrementCellsInPosition();
    }

    m_board->setEmptyCell(m_destineCell);
    m_board->incrementTries();
    //m_board->attemptWasExecuted();
}

bool Cell::up()
{
    if (!canUp())
        return false;

    swapCellsValues(this, m_upCell);
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

    swapCellsValues(this, m_dowCell);
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

    swapCellsValues(this, m_leftCell);
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

    swapCellsValues(this, m_rightCell);
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

void Cell::atualizeStatusGame(int currentValue, int nextValue, int expectedValue)
{
    if (currentValue != nextValue) {
        if (nextValue == expectedValue) {
            m_board->incrementCellsInPosition();
        } else {
            m_board->decrementCellsInPosition();
        }
    }
}

void Cell::calculeRowCol(int pos, int *row, int *col)
{
    *row = (pos-1)/SIZE_SIDE_BOARD;
    *col = ((pos-1)-((*row)*SIZE_SIDE_BOARD));
}

void Cell::calculeExpectedValue(int row, int col, int *absPos)
{

    *absPos = s_MatrixExpectedValues[row][col];
}

bool Cell::valueInPosition() const
{
    int expectedValue;
    Cell::calculeExpectedValue(m_row, m_col, &expectedValue);

    return m_value == expectedValue;
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

