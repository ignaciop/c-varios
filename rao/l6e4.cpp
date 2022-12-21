#include <iostream>

int main() {
    enum Rainbow {Red, Orange, Yellow, Green, Blue, Indigo, Violet};

    std::cout << "Here are the available colors: " << std::endl;
    std::cout << "Red: " << Red << std::endl;
    std::cout << "Orange: " << Orange << std::endl;
    std::cout << "Yellow: " << Yellow << std::endl;
    std::cout << "Green: " << Green << std::endl;
    std::cout << "Blue: " << Blue << std::endl;
    std::cout << "Indigo: " << Indigo << std::endl;
    std::cout << "Violet: " << Violet << std::endl;

    std::cout << "Enter a color: ";
    int color;
    std::cin >> color;

    switch (color) {
        case Red:
        case Orange:
        case Yellow:
        case Green:
        case Blue:
        case Indigo:
        case Violet:
            std::cout << color << " is in the rainbow!" << std::endl;
            break;
        default:
            std::cout << color << " is not in the rainbow :(" << std::endl;
            break;
    }

    return 0;
}