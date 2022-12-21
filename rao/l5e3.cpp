#include <iostream>

int main() {
    std::cout << "Enter a number i1 (1 for true, 0 for false): ";
    unsigned short i1;
    std::cin >> i1;
    

    std::cout << "Enter a number i2 (1 for true, 0 for false): ";
    unsigned short i2;
    std::cin >> i2;

    bool b1 = static_cast<bool>(i1);
    bool b2 = static_cast<bool>(i2);

    std::cout << "b1: " << std::boolalpha << b1 << std::endl;
    std::cout << "b2: " << std::boolalpha << b2 << std::endl;

    bool b3 = b1 & b2;
    bool b4 = b1 << b2;
    bool b5 = b1 >> b2;
    bool b6 = b1 | b2;
    bool b7 = b1 ^ b2;

    std::cout << "b1 & b2: " << std::boolalpha << b3 << std::endl;
    std::cout << "b1 << b2: " << std::boolalpha << b4 << std::endl;
    std::cout << "b1 >> b2: " << std::boolalpha << b5 << std::endl;
    std::cout << "b1 | b2: " << std::boolalpha << b6 << std::endl;
    std::cout << "b1 ^ b2: " << std::boolalpha << b7 << std::endl;

    return 0;
}


