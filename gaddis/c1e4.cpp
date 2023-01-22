#include <iostream>

int main() {
    double soil, seeds, fence;

    std::cout << "Enter the cost of the soil ";
    std::cin >> soil;

    std::cout << "Enter the cost of the flower seeds ";
    std::cin >> seeds;

    std::cout << "Enter the cost of the fence ";
    std::cin >> fence;

    double cost = soil + seeds + fence;

    std::cout << "The cost of the garden is " << cost << std::endl;

    return 0;
}