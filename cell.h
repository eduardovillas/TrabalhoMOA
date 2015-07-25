#ifndef MOA_CELL_H
#define MOA_CELL_H

class Board;

class Cell
{
public:
    Cell(char row, char col, char value = 0, Board *board = 0);
    Cell(const Cell &other);
    Cell();
    virtual ~Cell();

    Cell &operator=(const Cell &other);
    bool operator==(const Cell &other);

    void swap(const Cell &other);

    char getRow();
    char getCol();

    char getValue() const;
    void setValue(int value);

    void swapCellsValues(Cell *thisCell, Cell *m_destineCell);

    bool up();
    bool canUp() const;

    bool down();
    bool canDown() const;

    bool left();
    bool canLeft() const;

    bool right();
    bool canRight() const;

    void atualizeStatusGame(char currentValue, char nextValue, char expectedValue);
    void atualizeStatusGame(const Cell *tempThisCell, const Cell *currentCell);

    static void calculeRowCol(int pos, int *row, int *col);
    static void calculeExpectedValue(int row, int col, int *absPos);

    bool valueInPosition() const;
    void setBoard(Board *board);
private:
    void initAdjacentCells();
    char m_row;
    char m_col;
    char m_value;
    Board *m_board;

};

#endif // MOA_CELL_H
