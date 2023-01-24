#include <iostream>

int main() {
    std::cout << "Enter the first rectangle width: ";
    double width1 = 0.0;
    std::cin >> width1;

    std::cout << "Enter the first rectangle length: ";
    double length1 = 0.0;
    std::cin >> length1;

    std::cout << "Enter the second rectangle width: ";
    double width2 = 0.0;
    std::cin >> width2;

    std::cout << "Enter the first rectangle length: ";
    double length2 = 0.0;
    std::cin >> length2;

    double area1 = width1 * length1;
    double area2 = width2 * length2;

    if (area1 > area2) {
        std::cout << "The first rectangle has a greater area than the second rectangle" << std::endl;
    } else if (area1 < area2) {
        std::cout << "The second rectangle has a greater area than the first rectangle" << std::endl;
    } else {
        std::cout << "Both areas are equal" << std::endl;
    }
    
    return 0;
}