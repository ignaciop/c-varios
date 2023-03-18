#include <iostream>

int main() {
    for (int i = 0; i <= 10; i += 2) {
        std::cout << i << " ";
    }

    std::cout << '\b' << '\n';

    return 0;
}