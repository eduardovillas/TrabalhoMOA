

#ifndef MOA_BOARD_H
#define MOA_BOARD_H

#include "cell.h"
#include "moa_global.h"

class Board {

public: 
    Board();
    virtual ~Board();

    int at(int pos) const;
    int at(int x, int y) const;
    bool fillValues(int values[][SIZE_SIDE_BOARD]);

    bool up(int pos);
    bool canUp(int pos) const;
    bool canUp(int row, int col) const;

    bool down(int pos);
    bool canDown(int pos);
    bool canDown(int row, int col);

    bool left(int pos);
    bool canleft(int pos);
    bool canleft(int row, int col);

    bool right(int pos);
    bool canright(int pos);
    bool canright(int row, int col);

private:
    void calculeRowCol(int pos, int *row, int *col) const;
    void buildRelationshipCells();
    void fillCells();
    const Cell *getCell(int pos) const;
    const Cell *getCell(int row, int col) const;

    Cell m_arrayBoard[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD];
    Cell *emptyCell;
	   
};

#endif // MOA_BOARD_H
