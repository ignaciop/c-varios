#include <iostream>

int main() {
    int count = 0;

    for (int i = 1; i <= 10; ++i) {
        STEP:
        std::cout << "Enter a positive number: ";
        int n = 0;
        std::cin >> n;

        if (n < 0) {
            count++;
            goto STEP;
        }

        if (n == 0) {
            goto STEP;
        }
    }

    std::cout << "Negative numbers: " << count << std::endl;

    return 0;
}