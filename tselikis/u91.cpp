#include <iostream>

int main() {
    int sum = 0;
    int char_count = 0;
    char ch;

    while (true) {
        std::cout << "Enter a character: ";
        ch = std::cin.get();

        if (ch != 'q') {
            sum += ch;
            char_count++;

            if (sum > 500) {
                break;
            }

            std::cin.get();
        } else {
            break;
        }
    }

    std::cout << "You have entered " << char_count << ((char_count == 1) ? " character." : " characters.") << std::endl;

    return 0;
}