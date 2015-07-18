#include <iostream>
#include <iomanip>
#include <string>
#include <board.h>

void print(Board b);
void test(int values[][4]);

int main(int argc, char *argv[])
{


    Board b;

    int values[4][4] = {{ 1, 2, 3, 4},{ 5, 6, 7, 8},{ 9, 10, 11, 12},{ 13, 14, 15, 0}};

    std::cout << "Jogo do tabuleiro de 15 peças" << "!\n";
    if (!b.fillValues(values)) {
        std::cout << "Erro valores inválidos" << "!\n";
        return 1;
    }


    print(b);

//    while (true) {
        std::cout << "\n";
//        int c = getchar();
//        if (c == )
        b.up(16);
        print(b);


//    }

    return 0;
}

void print(Board b)
{
    std::cout << std::setw(2) << b.at(1) << " ";
    std::cout << std::setw(2) << b.at(2) << " ";
    std::cout << std::setw(2) << b.at(3) << " ";
    std::cout << std::setw(2) << b.at(4) << "\n";
    std::cout << std::setw(2) << b.at(5) << " ";
    std::cout << std::setw(2) << b.at(6) << " ";
    std::cout << std::setw(2) << b.at(7) << " ";
    std::cout << std::setw(2) << b.at(8) << "\n";
    std::cout << std::setw(2) << b.at(9) << " ";
    std::cout << std::setw(2) << b.at(10) << " ";
    std::cout << std::setw(2) << b.at(11) << " ";
    std::cout << std::setw(2) << b.at(12) << "\n";
    std::cout << std::setw(2) << b.at(13) << " ";
    std::cout << std::setw(2) << b.at(14) << " ";
    std::cout << std::setw(2) << b.at(15) << " ";
    std::cout << std::setw(2) << b.at(16) << "\n";
}

void test(int values[][4])
{
    values[0][0] = 70;
}
