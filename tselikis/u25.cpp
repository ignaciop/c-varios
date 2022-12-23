#include <iostream>
#include <cmath>

int main() {
    int i = 42;
    int j = 9;

    std::cout << "Remainder of " << i << "/" << j << " = "
                << i - (j*(i / j)) << std::endl;
    
    return 0;
}