#include <iostream>
#include <limits>

int main() {
    long l_min = std::numeric_limits<long>::min();
    long l_max = std::numeric_limits<long>::max();

    long long ll_min = std::numeric_limits<long long>::min();
    long long ll_max = std::numeric_limits<long long>::max();

    std::cout << "Long minimum: " << l_min << std::endl;
    std::cout << "Long maximum: " << l_max << std::endl;
    std::cout << "Long long minimum: " << ll_min << std::endl;
    std::cout << "Long long maximum: " << ll_max << std::endl;

    return 0;
}