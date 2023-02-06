#include <iostream>

int main () {
    int type = 1;
    int size = 1;

    do {
        std::cout << "Pattern type? ";
        std::cin >> type;
    } while (type < 1 || type > 2);

    do {
        std::cout << "Size? ";
        std::cin >> size;
    } while (size < 1 || size > 6);

    switch (type) {
        case 1:
            for(int i = size; i >= 1; --i) {
                for(int space = 0; space < size - i; ++space) {
                    std::cout << " ";
                }

                for(int j = i; j <= 2 * i - 1; ++j) {
                    std::cout << "*";
                }

                for(int j = 0; j < i - 1; ++j) {
                    std::cout << "*";
                }

                std::cout << std::endl;
            }

            break;            
        case 2:
            for(int i = 1, k = 0; i <= size; ++i, k = 0) {
                for(int space = 1; space <= size - i; ++space) {
                    std::cout <<" ";
                }

                while(k != 2 * i - 1) {
                    std::cout << "*";
                    ++k;
                }
                
                std::cout << std::endl;
            }    

            break;
    }

    return 0;
}