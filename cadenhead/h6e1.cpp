#include <iostream>

int main() {
    int i = 1;
    int count = 0;

    do {
       if (i % 16 == 0) {
            std::cout << i << " ";
            
            count++;
        }

        i++;
    } while (count < 100);

    std::cout << std::endl;

    return 0;
}