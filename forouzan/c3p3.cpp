#include <iostream>
#include <limits>

int main() {
    float f_min = std::numeric_limits<float>::min();
    float f_max = std::numeric_limits<float>::max();

    double d_min = std::numeric_limits<double>::min();
    double d_max = std::numeric_limits<double>::max();

    std::cout << "Float minimum: " << f_min << std::endl;
    std::cout << "Float maximum: " << f_max << std::endl;
    std::cout << "Double minimum: " << d_min << std::endl;
    std::cout << "Double maximum: " << d_max << std::endl;

    return 0;
}