#include <iostream>

int main() {
    std::cout << "Enter an integer: ";
    int i = 0;
    std::cin >> i;

    if (i & 1) {
        std::cout << "The number " << i << " is odd\n";
    } else {
        std::cout << "The number " << i << " is even\n";
    }
    
    return 0;
}