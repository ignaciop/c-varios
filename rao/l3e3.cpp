#include <iostream>

int main() {
    const float PI = 3.1415F;

    std::cout << "Enter radius of a circle: ";
    float radius;
    std::cin >> radius;

    const float area = PI * radius * radius;
    const float circumference = 2 * PI * radius;

    std::cout << "Area: " << area <<  std::endl;
    std::cout << "Circumference: " << circumference <<  std::endl;

    return 0;
}
