#include <iostream>

int main() {
    const int ARR_SIZE = 5;
    int values[ARR_SIZE] = {};

    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << "Enter integer value: ";
        std::cin >> values[i];
    }

    for (int i = 0; i < ARR_SIZE; i++) {
        int count = 0;

        for (int j = 0; j < ARR_SIZE; j++) {
            if (values[i] == values[j]) {
                count++;
            }
        }

        if (count > 1) {
            std::cout << values[i] << " is repeated " << count << " times.\n" << std::endl;
        }
    }
 
    return 0;
}

// Ambiguous text. What happens if array is {1, -3, 1, 50, -3, 1}?
// Should I return 2 (-3 appears 2 times) or 3 (-1 appears three times)??