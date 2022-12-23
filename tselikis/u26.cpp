#include <iostream>
#include <cmath>

int main() {
    float x = 7.2;
    float y = 5.4;

    int div = static_cast<int>(x / y);
    float frac = x - (div * y);

    std::cout << "Integer part of " << x << "/" << y << " = "
                << div << std::endl;
    std::cout << "Fractional part of " << x << "/" << y << " = "
                << frac << std::endl;
    
    return 0;
}