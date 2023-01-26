#include <iostream>
#include <iomanip>

int main() {
    const double K2M = 0.6214F;

    std::cout << "\nKPH\tMPH" << std::endl;
    std::cout << "---------------" << std::endl;

    for (int i = 40; i <= 120; i += 10) {
        std::cout << std::setw(3) << i << "\t" << std::setw(4) << i * K2M << std::endl;
    }

    return 0;
}