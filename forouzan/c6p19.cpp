#include <iostream>
#include <cstdlib>
#include <ctime>

void randomNumbers();

int main () {
    randomNumbers();
    
    return 0;
}

void randomNumbers() {
    const int LL = 1111;
    const int UL = 9999;

    // Seed
    srand(time(0));

    int count = 0;

    while (count < 100) {
        int num = LL + (rand() % (UL - LL + 1));

        if (num % 10 != 0) {
            std::cout << num << " ";
            count++;

            if (count % 10 == 0) {
                std::cout << std::endl;
            }
        }
    }
}