#include <iostream>

int main() {
    int i;

    std::cout << "Enter a positive integer: ";
    std::cin >> i;

    int fifts = i / 50;
    int rest = i % 50;


    int twents = rest / 20;
    rest %= 20;

    int tents = rest / 10;
    rest %= 10;

    std::cout << fifts << "*50, " << twents << "*20, "
                << tents << "*10, " << rest << "*1." << '\n';
    
    return 0;
}