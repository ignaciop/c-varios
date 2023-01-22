#include <iostream>

int main() {
    double length, width;

    std::cout << "Enter the garden length (in feet)  ";
    std::cin >> length;

    std::cout << "Enter the garden width (in feet)  ";
    std::cin >> width;

    double size = length * width;

    std::cout << "The garden measures " << size << " square feet." << std::endl;

    return 0;
}