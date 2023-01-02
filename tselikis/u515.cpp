#include <iostream>

int main() {
    std::cout << "Enter three integers: " << std::endl;
    int i, j, k = 0;
    std::cin >> i >> j >> k;

    std::cout << "Enter a choice (1, 2 or 3): " << std::endl;
    int choice = 0;
    std::cin >> choice;

    int count = 0;

    switch (choice) {
    case 1:
        if (i != j && j != k) {
            std::cout << "The three numbers are different." << std::endl;
        }
        break;
    case 2:
        if (i == j || i == k || j == k) {
            std::cout << "At least two of them are equal." << std::endl;
        }
        break;
    case 3:
        if (i >= -5 && i <= 5) {
            count++;
        }

        if (j >= -5 && j <= 5) {
            count++;
        }

        if (k >= -5 && k <= 5) {
            count++;
        }

        std::cout << "There are " << count << " numbers in [-5, 5] interval."
                    << std::endl;
    default:
        break;
    }
    
    return 0;
}