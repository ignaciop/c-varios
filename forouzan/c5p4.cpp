#include <iostream>

int main () {
    int positives = 0;
    int negatives = 0;

    int n = 1;

    do {
        std::cout << "Enter a number: ";
        std::cin >> n;

        if (n > 0) {
            positives++;
        }

        if (n < 0) {
            negatives++;
        }
            
    } while (n != 0);

    std::cout << "Positives: " << positives << std::endl;
    std::cout << "Negatives: " << negatives << std::endl;

    return 0;
}