#include <iostream>

int main() {
    std::cout << "Enter four integers: ";
    int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
    std::cin >> i1 >> i2 >> i3 >> i4;
    
    double avg = (i1 + i2 + i3 +i4) / 4.0F;

    std::cout << "Average: " << avg << std::endl;
    
    return 0;
}