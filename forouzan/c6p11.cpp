#include <iostream>
#include <iomanip>
#include <cmath>

double log2(int x);

int main () {
    for (int x = 1; x <= 10; x++) {
        std::cout << "log2(" << x << ") = " << std::fixed << std::right
                    << std::setw(3) << std::setprecision(2) << log2(x) << std::endl;
    }
    
    return 0;
}

double log2(int x) {
    return (log(x) / log(2));
}