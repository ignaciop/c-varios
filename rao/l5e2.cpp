#include <iostream>

int main() {
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    int result = number << 1 + 5 << 1;

    std::cout << result << std::endl;
    
    return 0;
}


