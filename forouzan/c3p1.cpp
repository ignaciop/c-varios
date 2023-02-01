#include <iostream>
#include <limits>

int main() {
    short s_min = std::numeric_limits<short>::min();
    short s_max = std::numeric_limits<short>::max();

    unsigned int ui_min = std::numeric_limits<unsigned int>::min();
    unsigned int ui_max = std::numeric_limits<unsigned int>::max();

    std::cout << "Short int minimum: " << s_min << std::endl;
    std::cout << "Short int maximum: " << s_max << std::endl;
    std::cout << "Unsigned int minimum: " << ui_min << std::endl;
    std::cout << "Unsigned int maximum: " << ui_max << std::endl;

    return 0;
}