#include <iostream>

int main () {
    int n1 = 1;
    int n2 = 1;

    do {
        std::cout << "Enter a first positive number: ";
        std::cin >> n1;  
    } while (n1 <= 0);

    do {
        std::cout << "Enter a second positive number: ";
        std::cin >> n2;  
    } while (n2 <= 0);

    std::cout << "Even numbers between " << n1 << " and " << n2 << ": {";
    for (int i = n1; i <= n2; i++) {
        if (i % 2 == 0) {
            std::cout << i << ", ";
        }
    }

    std::cout << "\b\b}";

    std::cout << "\nOdd numbers between " << n1 << " and " << n2 << ": {";
    for (int i = n1; i <= n2; i++) {
        if (i % 2 != 0) {
            std::cout << i << ", ";
        }
    }

    std::cout << "\b\b}" << std::endl;

    return 0;
}