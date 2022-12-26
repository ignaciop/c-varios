#include <iostream>

int main() {
    std::cout << "Enter total seconds: ";
    int seconds = 0;
    std::cin >> seconds;

    std::cout << (seconds / 3600) << "h " << ((seconds % 3600) / 60)  << "m " << (seconds % 60) << "s" << std::endl;

    return 0;
}