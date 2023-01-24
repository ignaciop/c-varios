#include <iostream>

int main() {
    int i = 32;
    int counter = 0;

    while (i <= 127) {
        std::cout << static_cast<char>(i) << " ";
        counter++;

        if (counter % 16 == 0) {
           std::cout << '\n';  
        }

        i++;
    }


    return 0;
}