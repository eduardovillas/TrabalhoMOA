#include <iostream>
#include <iomanip>
#include <string>
#include <board.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "moa_global.h"
#include "a_star.h"

void print(Board b);
void test(int values[][SIZE_SIDE_BOARD]);
void fillRandomValues(int values[][SIZE_SIDE_BOARD]);
//void solveBoardBruteForce(Board &b);
bool executeOp(Board &b);
void testBoard();
void testNodeTree();

int main(int argc, char *argv[])
{
    testNodeTree();

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

void test(int values[][SIZE_SIDE_BOARD])
{
    values[0][0] = 70;
}

//void solveBoardBruteForce(Board &b) {

////    A_Star a;
////    a.search(b);

//}

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

void testBoard()
{
    Board b;

    char values[SIZE_SIDE_BOARD][SIZE_SIDE_BOARD] = {{1,2,3,4},{12,13,14,5},{11,0,15,6},{10,9,8,7}};

    std::cout << "Jogo do tabuleiro de 15 peças" << "!\n";
    if (!b.fillValues(values)) {
        std::cout << "Erro valores inválidos" << "!\n";
        return;
    }

    std::cout << "\n";
    print(b);

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
    //    using namespace std;
    //    clock_t begin = clock();

    //    std::cout << "inicio da tentativa de resolcao" << "\n";

    //    solveBoardBruteForce(b);

    //    clock_t end = clock();
    //    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    //    std::cout << "resolucao em " << elapsed_secs/ 60 << " minutos "<< b.getTries() << " movimentos" << "\n";

    //    return 0;

}

void testNodeTree()
{
    Board *b = new Board();
    NodeTree<Board> *nodeb = new NodeTree<Board>(b);

    //NodeTree<Board> ** children = node->children();

    Board *c = new Board();

    NodeTree<Board> *nodeC = new NodeTree<Board>(c);

    nodeb->appendChildren(nodeC);

    delete nodeb;
}
