

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

    bool up();
    bool canUp() const;

    bool down();
    bool canDown();

    bool left();
    bool canleft();

    bool right();
    bool canright();

    void setEmptyCell(Cell *cell);
    Cell *getEmptyCell();

private:
    void calculeRowCol(int pos, int *row, int *col) const;
    void buildRelationshipCells();
    void fillCells();
    const Cell *getCell(int pos) const;
    const Cell *getCell(int row, int col) const;

    Cell m_arrayBoard[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD];
    Cell *m_emptyCell;
	   
};

#endif // MOA_BOARD_H
