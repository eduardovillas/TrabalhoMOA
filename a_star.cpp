#include "a_star.h"
#include <iostream>

A_Star::A_Star()
{

}

bool A_Star::search(Board board)
{

    // isso é a f(n) da quantidade de movimentos com a quantidade de pecas fora do lugar

    if (board.winGame()){
        std::cout << "aaaaaaaaaaaaaaaaaa";
        return true;
    }

    Board upBoard = board;
    Board dowBoad = board;
    Board rightBoad = board;
    Board leftBoard = board;

    if (upBoard.up()){
        search(upBoard);
    }

    if (dowBoad.down()){
        search(dowBoad);
    }

    if (rightBoad.right()){
        search(rightBoad);
    }

    if (leftBoard.left()){
        search(leftBoard);
    }

    return true;
}

