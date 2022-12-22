#include <iostream>

class Circle {
    private:
        const float PI = 3.1415F;
        float radius;

    public:
        Circle(float radiusInput) : 
            radius(radiusInput) {};
        float area();
        float circumference();
};

float Circle::area() {
    return (PI * radius * radius);
}

float Circle::circumference() {
    return (2 * PI * radius);
}

int main() {
    std::cout << "Enter a radius: ";
    float radius = 0;
    std::cin >> radius;

    Circle c1(radius);

    std::cout << "Area: " << c1.area() << std::endl;
    std::cout << "Circumference: " << c1.circumference() << std::endl;    

    return 0;
}

