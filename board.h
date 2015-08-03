#ifndef MOA_BOARD_H
#define MOA_BOARD_H

#include "cell.h"
#include "moa_global.h"
#include <string>

class Board {

public: 
    Board();
    Board(const Board & other);

    inline Board &operator=(const Board &other);
    inline bool operator<(const Board &other) const;
    inline bool operator>(const Board &other) const;

    virtual ~Board();

    inline bool fillValues(char values[][SIZE_SIDE_BOARD]);
    char at(int pos) const;
    char at(int x, int y) const;

    inline bool up();
    inline bool canUp() const;

    inline bool down();
    inline bool canDown();

    inline bool left();
    inline bool canleft();

    inline bool right();
    inline bool canright();

    inline void setEmptyCell(Cell *cell);
    inline Cell *getEmptyCell();

    inline char getCellsInPosition() const;
    inline void setCellsInPosition(unsigned char value);

    inline void incrementCellsInPosition();
    inline void decrementCellsInPosition();

    inline bool winGame();
    inline void incrementTries();
    inline unsigned long long int getTries();

    inline Cell *getUpCell();
    inline Cell *getDownCell();
    inline Cell *getLeftCell();
    inline Cell *getRightCell();

    inline std::string getKey();
    inline void recalculeKey();

    inline unsigned long long getMoviments() const;
    inline void setMoviments(unsigned long long moviments);

private:
    inline bool copyCells(const Cell arrayBoard[][SIZE_SIDE_BOARD]);
    inline void swap(const Board &other);
    inline void createCells();
    inline Cell *getCell(char pos);
    inline Cell *getCell(int row, int col);

    Cell m_arrayBoard[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD];
    Cell *m_emptyCell;
    unsigned char m_cellsInPosition;
    unsigned char m_cellsNotInPosition;
    unsigned long long int m_moviments;
    std::string m_key;
};

inline Board &Board::operator=(const Board &other)
{
    createCells();
    swap(other);

    return *this;
}

inline bool Board::operator<(const Board &other) const
{
    return m_cellsNotInPosition + m_moviments < other.m_cellsNotInPosition + other.m_moviments;
}

inline bool Board::operator>(const Board &other) const
{
    return m_cellsNotInPosition + m_moviments > other.m_cellsNotInPosition + other.m_moviments;
}

inline bool Board::fillValues(char values[][SIZE_SIDE_BOARD])
{
    m_emptyCell = 0;
    m_key.clear();

    for (int row = 0; row < SIZE_SIDE_BOARD; ++row) {
        for (int col = 0; col < SIZE_SIDE_BOARD; ++col) {
            char value = values[row][col];
            Cell *cell = &m_arrayBoard[row][col];

            if (value == 0 ) {
                if (m_emptyCell != 0)
                    return false;
                m_emptyCell = cell;
            }

            m_key.append(std::to_string(value));
            m_key.append(" ");

            cell->setValue(value);
        }
    }

    m_moviments = 0;
    return m_emptyCell != 0;
}

inline bool Board::up()
{
    return m_emptyCell->up();
}

inline bool Board::canUp() const
{
    return m_emptyCell->canUp();
}

inline bool Board::down()
{
    return m_emptyCell->down();
}

inline bool Board::canDown()
{
    return m_emptyCell->canDown();
}

inline bool Board::left()
{
    return m_emptyCell->left();
}

inline bool Board::canleft()
{
    return m_emptyCell->canLeft();
}

inline bool Board::right()
{
    return m_emptyCell->right();
}

inline bool Board::canright()
{
    return m_emptyCell->canRight();
}

inline void Board::setEmptyCell(Cell *cell)
{
    m_emptyCell = cell;
}

inline Cell *Board::getEmptyCell()
{
    return m_emptyCell;
}

inline void Board::createCells()
{
    m_key.clear();
    for (int row =0 ; row < SIZE_SIDE_BOARD; ++row) {
        for (int col = 0; col < SIZE_SIDE_BOARD; ++col) {

            int expectedValue;
            Cell::calculeExpectedValue(row, col, &expectedValue);
            Cell cell(row, col, expectedValue, this);
            m_arrayBoard[row][col] = cell;
            m_key.append(std::to_string(cell.getValue()));
            m_key.append(" ");

        }
    }

    setCellsInPosition(SIZE_SIDE_BOARD*SIZE_SIDE_BOARD);
}

inline Cell *Board::getCell(char pos)
{
    int row;
    int col;
    Cell::calculeRowCol(pos, &row, &col);

    return getCell(row, col);
}

inline Cell *Board::getCell(int row, int col)
{
    return &m_arrayBoard[row][col];
}

inline unsigned long long Board::getMoviments() const
{
    return m_moviments;
}

inline void Board::setMoviments(unsigned long long moviments)
{
    m_moviments = moviments;
}


inline char Board::getCellsInPosition() const
{
    return m_cellsInPosition;
}

inline void Board::setCellsInPosition(unsigned char value)
{
    m_cellsInPosition = value;
    m_cellsNotInPosition = m_cellsInPosition - 16;
}

inline void Board::incrementCellsInPosition()
{
    ++m_cellsInPosition;
    --m_cellsNotInPosition;
}

inline void Board::decrementCellsInPosition()
{
    --m_cellsInPosition;
    ++m_cellsNotInPosition;
}

inline bool Board::winGame()
{
    return getCellsInPosition() >= ((SIZE_SIDE_BOARD*SIZE_SIDE_BOARD));
}

inline void Board::incrementTries()
{
    ++m_moviments;
}

inline unsigned long long Board::getTries()
{
    return m_moviments;
}

inline Cell *Board::getUpCell()
{
    int row = m_emptyCell->getRow();
    int col = m_emptyCell->getCol();

    if (row == 0)
        return 0;

    return &m_arrayBoard[--row][col];
}

inline Cell *Board::getDownCell()
{
    int row = m_emptyCell->getRow();
    int col = m_emptyCell->getCol();

    if (row == SIZE_SIDE_BOARD-1)
        return 0;

    return &m_arrayBoard[++row][col];
}

inline Cell *Board::getLeftCell()
{
    int row = m_emptyCell->getRow();
    int col = m_emptyCell->getCol();

    if (col == 0)
        return 0;

    return &m_arrayBoard[row][--col];

}

inline Cell *Board::getRightCell()
{
    int row = m_emptyCell->getRow();
    int col = m_emptyCell->getCol();

    if (col == SIZE_SIDE_BOARD-1)
        return 0;

    return &m_arrayBoard[row][++col];

}

inline std::string Board::getKey()
{
    return m_key;
}

inline void Board::recalculeKey()
{
    m_key.clear();
    for (int row = 0; row < SIZE_SIDE_BOARD; ++row){
        for (int col = 0; col < SIZE_SIDE_BOARD; ++col) {
            m_key.append(std::to_string(m_arrayBoard[row][col].getValue()));
            m_key.append(" ");
        }
    }

}

inline bool Board::copyCells(const Cell arrayBoard[][SIZE_SIDE_BOARD])
{

    m_key.clear();
    for (int row = 0; row < SIZE_SIDE_BOARD; ++row){
        for (int col = 0; col < SIZE_SIDE_BOARD; ++col) {
            m_arrayBoard[row][col] = arrayBoard[row][col];
            m_arrayBoard[row][col].setBoard(this);
            m_key += std::to_string(m_arrayBoard[row][col].getValue()) + " ";
        }
    }

    return true;
}

inline void Board::swap(const Board &other)
{
    copyCells(other.m_arrayBoard);
    int row;
    int col;

    row = other.m_emptyCell->getRow();
    col = other.m_emptyCell->getCol();

    m_emptyCell = &m_arrayBoard[row][col];
    m_cellsInPosition = other.m_cellsInPosition;
    m_cellsNotInPosition = other.m_cellsNotInPosition;
    m_moviments = other.m_moviments;
    m_key.clear();
    m_key.append(m_key);

}

#endif // MOA_BOARD_H
