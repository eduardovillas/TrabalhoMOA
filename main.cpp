#include <iostream>
#include <iomanip>
#include <string>
#include <board.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "moa_global.h"
#include "a_star.h"

int main(int argc, char *argv[])
{

//    clock_t begin = clock();

    Board * b = new Board();

    char values[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD];

//    for (int j = 1 ;j < argc; ++j ) {

//    }
   /*char values8[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD]= {{ 2, 3, 4, 5},
                                                     { 1,13,14, 6},
                                                     {12,11,15, 0},
                                                     {10, 9, 8, 7}};

    char values13[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD] = {{ 2, 3, 4, 5},
                                                     { 1,13,14, 6},
                                                     { 0,11,15, 7},
                                                     {12,10, 9, 8}};
*/
    char values28[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD] = {{ 2, 4, 5, 6},
                                                       { 0, 3,14,13},
                                                       { 1,11, 9, 7},
                                                       {12,15,10, 8}};

    b->fillValues(values28);

    NodeTree<Board> *root = new NodeTree<Board>(b);

    A_Star a_star(root);

    if (a_star.search())
        std::cout <<  a_star.getMovements();
    else
        std::cout << "suco de laranja";

    delete root;

//    clock_t end = std::clock();
//    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

//    std::cout << "resolucao em " << elapsed_secs << " segundos "" movimentos" << "\n";


    return 0;
}

void print(Board b)
{
    for (int i = 1; i <= SIZE_SIDE_BOARD*SIZE_SIDE_BOARD; ++i) {
        std::cout << std::setw(2) << (int)b.at(i) << " ";
        if (i % SIZE_SIDE_BOARD == 0)
            std::cout << "\n";
    }

}

