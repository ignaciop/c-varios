#include <iostream>

int main () {
    for (int i = 1; i <= 100; i++) {
        if (i % 7 == 0) {
            std::cout << i << " ";
        }
    }

    std::cout << "\n";

    return 0;
}