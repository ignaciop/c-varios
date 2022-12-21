#include <iostream>

const float PI = 3.1415F;

float volume(float radius);
float volume(float radius, float height);

int main() {
    std::cout << "Enter radius: ";
    float radius;
    std::cin >> radius;

    std::cout << "Enter height: ";
    float height;
    std::cin >> height;

    std::cout << "Volume of sphere: " << volume(radius) << std::endl;
    std::cout << "Volume of a cylinder: " << volume(radius, height) << std::endl;

    return 0;
}

float volume(float radius) {
    return (4 * PI * radius * radius * radius / 3);
}

float volume(float radius, float height) {
    return (PI * radius * radius * height);
}