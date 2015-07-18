#ifndef MOA_CELL_H
#define MOA_CELL_H

class Board;

class Cell
{
public:
    Cell(int row, int col, int value = 0);
    Cell(const Cell &other);
    Cell();
    virtual ~Cell();

    Cell &operator=(const Cell &other);
    bool operator==(const Cell &other);

    void swap(const Cell &other);

    int getRow();
    int getCol();

    int getValue() const;
    void setValue(int value);

    Cell *getUpCell() const;
    void setUpCell(Cell *upCell);

    Cell *getDowCell() const;
    void setDowCell(Cell *dowCell);

    Cell *getLeftCell() const;
    void setLeftCell(Cell *leftCell);

    Cell *getRightCell() const;
    void setRightCell(Cell *rightCell);

    void swapCells(Cell *thisCell, Cell *m_destineCell);

    bool up();
    bool canUp() const;

    bool down();
    bool canDown() const;

    bool left();
    bool canLeft() const;

    bool right();
    bool canRight() const;

private:
    void initAdjacentCells();
    int m_row;
    int m_col;
    int m_value;
    Cell *m_upCell;
    Cell *m_dowCell;
    Cell *m_leftCell;
    Cell *m_rightCell;
    Board *board;

};

#endif // MOA_CELL_H