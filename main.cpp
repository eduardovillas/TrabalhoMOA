#include <iostream>
#include <string>
#include <board.h>

void print(Board b);

int main(int argc, char *argv[])
{

    std::string name;
    std::cout << "What is your name? ";

    std::cout << "Hello, " << name << "!\n";
    Board b;

    int values[4][4] = {{ 1, 2, 3, 4},{ 5, 6, 7, 8},{ 9, 10, 11, 12},{ 13, 14, 15, 0}};

    b.fill(values);

    print(b);

    return 0;
}

void print(Board b)
{
    std::cout << b.at(1) << " ";
    std::cout << b.at(2) << " ";
    std::cout << b.at(3) << " ";
    std::cout << b.at(4) << "\n";
    std::cout << b.at(5) << " ";
    std::cout << b.at(6) << " ";
    std::cout << b.at(7) << " ";
    std::cout << b.at(8) << "\n";
    std::cout << b.at(9) << " ";
    std::cout << b.at(10) << " ";
    std::cout << b.at(11) << " ";
    std::cout << b.at(12) << "\n";
    std::cout << b.at(13) << " ";
    std::cout << b.at(14) << " ";
    std::cout << b.at(15) << " ";
    std::cout << b.at(16) << "\n";
}
