#include <iostream>

int main() {

    int ai[5] = {1, 2, 3, 4, 5};

    for (int j = 0; j <= 4; j++) {
        std::cout << ai[j] << " ";
    }

    std::cout << std::endl;

    for (int j = 4; j >= 0; j--) {
        std::cout << ai[j] << " ";
    }

    std::cout << std::endl;

    return 0;
}


