#include <iostream>

int main() {
    std::cout << "Enter a boolean: ";
    bool b1;
    std::cin >> b1;
    std::cin.clear();
    

    std::cout << "Enter another boolean: ";
    bool b2;
    std::cin >> b2;
    std::cin.clear();

    std::cout << "1º boolean: " << std::boolalpha << b1 << std::endl;
    std::cout << "2º boolean: " << std::boolalpha << b2 << std::endl;

    return 0;
}


