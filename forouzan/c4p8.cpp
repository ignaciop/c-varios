#include <iostream>

int main() {
    std::cout << "Enter x coordinate: ";
    double x = 0.0;
    std::cin >> x;

    std::cout << "Enter y coordinate: ";
    double y = 0.0;
    std::cin >> y;

    int quarter = 0;

    if (x >= 0) {
        if (y >= 0) {
            quarter = 1;
        } else {
            quarter = 4;
        }
    } else {
        if (y >= 0) {
            quarter = 2;
        } else {
            quarter = 3;
        }
    }

    std::cout << "(" << x << ", " << y << ")" << " is in quarter " << quarter << std::endl;
    
    return 0;
}