#include <iostream>

int main() {
    const int ARRAY_SIZE = 100;
    int numbers[ARRAY_SIZE] = {};

    int *p = nullptr;
    int *last_stored = nullptr;
    int num = 1;
    int total_inserted = 0;
    int count = 1;

    for (p = numbers; p <= numbers + (ARRAY_SIZE - 1); p++) {
        std::cout << "Enter number_" << count << ": ";
        std::cin >> num;

        count++;

        if (num == 0) {
            break;
        }

        if (p == numbers) {
            *p = num;
            last_stored = p;

            total_inserted++;
        } else {

            if (num < *last_stored && num != -1) {
                *p = num;
                last_stored = p;
                total_inserted++;
            } else {
                continue;
            }
        }
    }

    std::cout << "{";

    for (p = numbers; p <= numbers + (ARRAY_SIZE - 1); p++) {
        if (*p != 0) {
            std::cout << *p << ", ";
        }
    }

    std::cout << "\b\b}\n";
    std::cout << "Number of items stored: " << total_inserted << std::endl;

    return 0;
}