#include <iostream>
#include <cstdlib>
#include <ctime>

int main () {
    const int LL = 2;
    const int UL = 10;

    // Seed
    srand(time(0));

    int rn = LL + (rand() % (UL - LL + 1));

    while (rn % 2 != 0) {
        rn = LL + (rand() % (UL - LL + 1));
    }

    std::cout << rn << std::endl;
    
    return 0;
}