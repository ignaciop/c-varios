#include <iostream>

int main() {
    for (int i = 111; i <= 999; ++i) {
        int cent = i / 100;
        int uni = (i % 100) % 10;

        if (cent != 4 && uni != 6) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}