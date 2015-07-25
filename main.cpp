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
bool executeOp(Board &b);

int main(int argc, char *argv[])
{
    Board b;
    Board a;

    int values[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD] = {{1,2,3,4},{12,13,14,5},{11,0,15,6},{10,9,8,7}};

    std::cout << "Jogo do tabuleiro de 15 peças" << "!\n";
    if (!b.fillValues(values)) {
        std::cout << "Erro valores inválidos" << "!\n";
        return 1;
    }

    std::cout << "\n";
    print(b);
    a = b;
    while (true) {
        int c = getchar();
        if (c == 10)
            continue;
        std::cout << "char " << c << "\n";
        if (c == 48) {
            std::cout << "saindo " << "\n";
            break;
        } else if (c == 52) {
            b.left();
        } else if (c == 54) {
            b.right();
        } else if (c == 56) {
            b.up();
        } else if (c == 50) {
            b.down();
        } else {
            std::cout << "tecla invalids " << "\n";
            continue;
        }
        if (b.winGame()) {
            print(b);
            std::cout << "O JOGO FOI VENCIDO " << "\n";
            break;
        }

        std::cout << "\n";
        print(b);
    }

    std::cout << "\n";
    print(a);
    while (true) {
        int c = getchar();
        if (c == 10)
            continue;
        std::cout << "char " << c << "\n";
        if (c == 48) {
            std::cout << "saindo " << "\n";
            break;
        } else if (c == 52) {
            a.left();
        } else if (c == 54) {
            a.right();
        } else if (c == 56) {
            a.up();
        } else if (c == 50) {
            a.down();
        } else {
            std::cout << "tecla invalids " << "\n";
            continue;
        }
        if (a.winGame()) {
            print(a);
            std::cout << "O JOGO FOI VENCIDO " << "\n";
            break;
        }

        std::cout << "\n";
        print(a);

    }

//    using namespace std;
//    clock_t begin = clock();

//    std::cout << "inicio da tentativa de resolcao" << "\n";

//    solveBoardBruteForce(b);

//    clock_t end = clock();
//    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

//    std::cout << "resolucao em " << elapsed_secs/ 60 << " minutos "<< b.getTries() << " movimentos" << "\n";

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

    int maximumCellsInPosition = 0;
    srand(time(NULL));
    std::cout << "movimentos=" << b.getTries() << " peças em posicao=" << b.getCellsInPosition() << " maximo de peças em posicao=" << maximumCellsInPosition << "\n";
    unsigned long long int tries = 0;
    while (!b.winGame()) {
        if (!executeOp(b))
            continue;
        ++tries;
        maximumCellsInPosition = std::max(maximumCellsInPosition, b.getCellsInPosition());
        if (tries >=  10000000){
            srand(time(NULL));
            tries = 0;
            std::cout << "movimentos=" << b.getTries() << " peças em posicao=" << b.getCellsInPosition() << " maximo de peças em posicao=" << maximumCellsInPosition << "\n";
            print(b);
        }

    }

}

bool executeOp(Board &b)
{
    int op;
    op = (rand() % 4)+1;

    if (op == 1)
        return b.up();
    else if (op == 2)
        return b.down();
    else if (op == 3)
        return b.left();
    else if (op == 4)
        return b.right();
    else
        std::cout << "valor invalido";

    return false;
}
