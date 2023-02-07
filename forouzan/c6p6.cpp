#include <iostream>
#include <cstdlib>
#include <ctime>

int main () {
    // Seed
    srand(time(0));

    for (int i = 1; i <= 10; i++) {
        int rn = rand() % 2;
        
        if (rn == 1) {
            std::cout << "Head" << std::endl;
        } else {
            std::cout << "Tail" << std::endl;
        }
    }
    
    return 0;
}