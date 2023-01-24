#include <iostream>

int main() {
    int value = 1;
    int sum = 0;

    do {
        std::cout << "Enter a positive integer value: ";
        std::cin >> value;
    } while (value <= 0);

    for (int i = 1; i <= value; i++) {
        sum += i;
    }

    std::cout << "Sum from 1 to " << value << " = " << sum << std::endl;

    return 0;
}