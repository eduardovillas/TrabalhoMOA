#ifndef MOA_BOARD_H
#define MOA_BOARD_H

#include "cell.h"
#include "moa_global.h"

class Board {

public: 
    Board();/*TODO: CONSTRUTOR DE COPIA E DE ATRIBUICAO*/
    virtual ~Board();

    bool fillValues(int values[][SIZE_SIDE_BOARD]);
    int at(int pos) const;
    int at(int x, int y) const;

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

    Cell *getUpCell();
    Cell *getDownCell();
    Cell *getLeftCell();
    Cell *getRightCell();

private:
    void createCells();
    Cell *getCell(int pos);
    Cell *getCell(int row, int col);

    Cell m_arrayBoard[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD];
    Cell *m_emptyCell;
    int m_cellsInPosition;
    unsigned long long int m_tries;
};

#endif // MOA_BOARD_H
