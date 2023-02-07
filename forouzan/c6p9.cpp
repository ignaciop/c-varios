#include <iostream>
#include <iomanip>
#include <cmath>

int main () {
    for (int i = 0; i < 10; i++) {
        std::cout << "sqrt(" << i << ") = " << std::fixed
                    << std::setw(4) << std::setprecision(2) << sqrt(i) << std::endl;
    }
    
    return 0;
}