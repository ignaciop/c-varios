#include <iostream>

int main() {
    unsigned int num, pos;

    std::cout << "Enter number: ";
    std::cin >> num;

    std::cout << "Enter bit position [1-32]: ";
    std::cin >> pos;

    std::cout << "bit" << pos << " is " << ((num >> (pos-1)) & 1) << '\n';
    
    return 0;
}