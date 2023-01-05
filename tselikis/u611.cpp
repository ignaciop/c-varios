#include <iostream>

int main() {
    int count = 0;
    int previous = 0;

    for (int i = 1; i <= 10; ++i) {
        std::cout << "Enter an integer: ";
        int n = 0;
        std::cin >> n;

        // Set first value of previous to n
        if (i == 1) {
            previous = n;
        }
        
        if (previous + 1 == n) {
            count++;
        }

        previous = n;
    }

    std::cout << "Number of succesive values: " << count << std::endl;

    return 0;
}