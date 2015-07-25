#ifndef MOA_BOARD_H
#define MOA_BOARD_H

#include "cell.h"
#include "moa_global.h"

class Board {

public: 
    Board();
    Board(const Board & other);

    Board &operator=(const Board &other);

    virtual ~Board();

    bool fillValues(char values[][SIZE_SIDE_BOARD]);
    char at(int pos) const;
    char at(int x, int y) const;

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

    char getCellsInPosition() const;
    void setCellsInPosition(char value);

    void incrementCellsInPosition();
    void decrementCellsInPosition();

    bool winGame();
    void incrementTries();
    unsigned long long int getTries();

    Cell *getUpCell();
    Cell *getDownCell();
    Cell *getLeftCell();
    Cell *getRightCell();

private:
    bool copyCells(const Cell arrayBoard[][SIZE_SIDE_BOARD]);
    void swap(const Board &other);
    void createCells();
    Cell *getCell(char pos);
    Cell *getCell(int row, int col);

    Cell m_arrayBoard[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD];
    Cell *m_emptyCell;
    char m_cellsInPosition;
    unsigned long long int m_tries;
};

#endif // MOA_BOARD_H
