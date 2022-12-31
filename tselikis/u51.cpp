#include <iostream>

int main() {
    const float FIXED_PRICE = 100.0;

    std::cout << "Enter three prices: ";
    float i, j, k;
    std::cin >> i >> j >> k;

    std::cout << ((i >= FIXED_PRICE || j >= FIXED_PRICE || k >= FIXED_PRICE) ? ("At least one of them costs $100") : ("None of them cost more than $100")) << std::endl;
    
    return 0;
}