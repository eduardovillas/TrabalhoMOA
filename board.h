
#ifndef MOA_BOARD_H
#define MOA_BOARD_H

class Board {

public: 
    Board();
    ~Board();

    int at(int pos) const;
    int at(int x, int y) const;
    void fill(int values[][4]);

private:
    void calculeRowCol(int pos, int *row, int *col) const;

   	unsigned int m_arrayBoard[4][4];
	   
};

#endif // MOA_BOARD_H
