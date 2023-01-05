#include <iostream>

int main() {
    int sum = 0;
    int count = 0;
    int number = 0;

    do {
        std::cout << "Enter an integer number: ";
        std::cin >> number;

        sum += number;
        count++;

    } while (sum <= 100) ;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Numbers entered: " << count << std::endl;

    return 0;
}