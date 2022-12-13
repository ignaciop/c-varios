#include <iostream>

int main() {
    int grade;
    int scale;

    std::cout << "Enter a grade (1–100): ";
    std::cin >> grade;

    std::cout << "Enter a scale (1–100): ";
    std::cin >> scale;


    if (grade >= scale) {
        std::cout << "\nYou passed!\n";
    } else {
        std::cout << "\nYou have not passed!\n";
    }

    return 0;
}