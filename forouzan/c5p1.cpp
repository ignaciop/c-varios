#include <iostream>

int main () {
    int type = 1;
    int size = 1;

    do {
        std::cout << "Pattern type? ";
        std::cin >> type;
    } while (type < 1 || type > 4);

    do {
        std::cout << "Size? ";
        std::cin >> size;
    } while (size < 1 || size > 9);

    switch (type) {
        case 1:
            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= i; j++) {
                    std::cout << "*";

                    if (j == i) {
                        std::cout << "\n";
                    }
                }
            }

            break;
        case 2:
            for (int i = 1; i <= size; i++) {
                for (int j = size; j >= i; j--) {
                    std::cout << "*";

                    if (j == i) {
                        std::cout << "\n";
                    }
                }
            }

            break;
        case 3:
            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= size; j++) {
                    if (j < i) {
                        std::cout << " ";
                    } else {
                        std::cout << "*";
                    }

                    if (j == size) {
                        std::cout << "\n";
                    }
                }
            }

            break;
        case 4:
            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= size; j++) {

                    if (j <= size - i) {
                        std::cout << " ";
                    } else {
                        std::cout << "*";
                    }

                    if (j == size) {
                        std::cout << "\n";
                    }
                }
            }

            break;
    }

    return 0;
}