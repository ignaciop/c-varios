#include <iostream>
#include <iomanip>
#include <cmath>

int main () {
    for (int i = 0; i < 10; i++) {
        std::cout << i << "^(1/3) = " << std::fixed
                    << std::setw(4) << std::setprecision(2) << pow(i, 1.0F / 3) << std::endl;
    }
    
    return 0;
}