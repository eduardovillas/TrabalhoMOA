

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

    int getCellsInPosition() const;
    void setCellsInPosition(int value);

    void incrementCellsInPosition();
    void decrementCellsInPosition();

    bool winGame();
    void incrementTries();
    unsigned long long int getTries();

private:
    void buildRelationshipCells();
    void fillCells();
    const Cell *getCell(int pos) const;
    const Cell *getCell(int row, int col) const;

    Cell m_arrayBoard[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD];
    Cell *m_emptyCell;
    int m_cellsInPosition;
    unsigned long long int m_tries;
};

#endif // MOA_BOARD_H
