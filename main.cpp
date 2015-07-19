#include <iostream>
#include <iomanip>
#include <string>
#include <board.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "moa_global.h"


void print(Board b);
void test(int values[][SIZE_SIDE_BOARD]);
void fillRandomValues(int values[][SIZE_SIDE_BOARD]);
void solveBoardBruteForce(Board &b);
void executeOp(Board &b);

int main(int argc, char *argv[])
{
    Board b;

    int values[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD] = {{ 15, 2, 9, 4},{ 10, 6, 7, 8},{ 3, 5, 11, 12},{ 13, 0, 14, 1}};

    std::cout << "Jogo do tabuleiro de 15 peças" << "!\n";
    if (!b.fillValues(values)) {
        std::cout << "Erro valores inválidos" << "!\n";
        return 1;
    }

    using namespace std;
    clock_t begin = clock();


    std::cout << "inicio da tentativa de resolcao" << "\n";
    solveBoardBruteForce(b);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    std::cout << "resolucao em " << elapsed_secs/ 60 << " minutos" << "\n";

//    std::cout << "\n";
//    print(b);
//    while (true) {
//        int c = getchar();
//        if (c == 10)
//            continue;
//        std::cout << "char " << c << "\n";
//        if (c == 48) {
//            std::cout << "saindo " << "\n";
//            break;
//        } else if (c == 52) {
//            b.left();
//        } else if (c == 54) {
//            b.right();
//        } else if (c == 56) {
//            b.up();
//        } else if (c == 50) {
//            b.down();
//        } else {
//            std::cout << "tecla invalids " << "\n";
//            continue;
//        }
//        if (b.winGame()) {
//            std::cout << "O JOGO FOI VENCIDO " << "\n";
//            break;
//        }

//        std::cout << "\n";
//        print(b);
//    }


    return 0;
}

void print(Board b)
{
    for (int i = 1; i <= SIZE_SIDE_BOARD*SIZE_SIDE_BOARD; ++i) {
        std::cout << std::setw(2) << b.at(i) << " ";
        if (i % SIZE_SIDE_BOARD == 0)
            std::cout << "\n";
    }

}

void test(int values[][SIZE_SIDE_BOARD])
{
    values[0][0] = 70;
}

void solveBoardBruteForce(Board &b) {

    while (!b.winGame()) {
        executeOp(b);
    }

}

void executeOp(Board &b)
{
    int op;
    op = (rand() % 4)+1;

    if (op == 1)
        b.up();
    else if (op == 2)
        b.down();
    else if (op == 3)
        b.left();
    else if (op == 4)
        b.right();

}
