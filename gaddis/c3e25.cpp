#include <iostream>

int main() {
    std::cout << "Enter the length of the row (in feet): ";
    double r = 0.0;
    std::cin >> r;

    std::cout << "Enter the amount of space used by an end-post assembly (in feet): ";
    double e = 0.0;
    std::cin >> e;

    std::cout << "Enter the amount of space between the vines (in feet): ";
    double s = 0.0;
    std::cin >> s;

    double v = (r - 2 * e) / s;

    std::cout << "Grapevines that will fit in a row: " << v << std::endl;

    return 0;
}