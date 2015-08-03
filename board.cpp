#include "board.h"

Board::Board() : m_emptyCell(0) {
    createCells();
}

Board::Board(const Board &other)
{
    createCells();
    swap(other);
}


Board::~Board()
{
    m_key.clear();
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




