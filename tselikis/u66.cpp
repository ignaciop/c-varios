#include <iostream>

int main() {
    int count = 0;
    int number = 0;
    int previous_number = 0;

    while (count < 100) {
        std::cout << "Enter an integer number: ";
        std::cin >> number;

        // First loop sets previous to a value less than actual number
        // to actually insert all possibilities (negative, zero and positive values)
        // If this is not present and you entered first a negative value; because
        // previous value is set to 0 (line 6), the program does not make any comparison
        // which is wrong.
        if (count == 0) {
            previous_number = number - 1;
        }

        count++;

        if (previous_number > number) {
            break;
        }

        previous_number = number;
    }

    std::cout << "Numbers entered: " << count << std::endl;

    return 0;
}