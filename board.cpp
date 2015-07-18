#include "board.h"

Board::Board() {
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
    return m_arrayBoard[x][y];
}

void Board::fill(int values[][4])
{
    for (int i = 1;i<=16;++i) {
        int row;
        int col;
        calculeRowCol(i, &row, &col);
        m_arrayBoard[row][col] = values[row][col];
    }
}

void Board::calculeRowCol(int pos, int *row, int *col) const
{
    *row = (pos-1)/4;
    *col = ((pos-1)-(*row*4));
}

