#include <iostream>

int main() {
    int number_sum = 0;
    int letter_sum = 0;
    int other_sum = 0;
    int star_count = 0;
    char ch;

    std::cout << "Enter characters: ";
    ch = std::cin.get();

    while (star_count < 2) {
        if (ch == '*') {
            star_count++;
        }

        if (star_count == 1) {
            if (ch >= '0' && ch <= '9') {
                number_sum++;
            } else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                letter_sum++;
            } else {
                if (ch != '*') {
                    other_sum++;
                }
            }
        }

        ch = std::cin.get();
    }

    std::cout << "Between first two stars (letters: " << letter_sum
                << ", digits: " << number_sum << ", other: " << other_sum
                    << ")." << std::endl;

    return 0;
}