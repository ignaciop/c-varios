#include <iostream>
#include <cstdlib>
#include <ctime>

int main () {
    const int LL = 1;
    const int UL = 9;

    // Seed
    srand(time(0));

    for (int i = 1; i <= 10; i++) {
        int rn = LL + (rand() % (UL - LL + 1));
        double rnd = static_cast<double>(rn) / 10; 
        
        std::cout << rnd << " ";
    }

    std::cout << std::endl;
    
    return 0;
}