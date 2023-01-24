#include <iostream>

int main() {
    const double PI = 3.14159F;

    std::cout << "Geometry Calculator" << std::endl;
    std::cout << "\t1. Calculate the Area of a Circle" << std::endl;
    std::cout << "\t2. Calculate the Area of a Rectangle" << std::endl;
    std::cout << "\t3. Calculate the Area of a Triangle" << std::endl;
    std::cout << "\t4. Quit" << std::endl;
    std::cout << "Enter your choice (1-4): ";

    int choice = 0;
    std::cin >> choice;

    double area = 0.0;
    double radius = 0.0;
    double length = 0.0;
    double width = 0.0;
    double base = 0.0;
    double height = 0.0;

    switch (choice) {
        case 1:
            std::cout << "Circle radius: ";
            std::cin >> radius;

            area = PI * radius * radius;

            std::cout << "Area: " << area << std::endl;

            break;

        case 2:
            std::cout << "Rectangle length: ";
            std::cin >> length;

            std::cout << "Rectangle width: ";
            std::cin >> width;

            area = length * width;

            std::cout << "Area: " << area << std::endl;

            break;

        case 3:
            std::cout << "Triangle base: ";
            std::cin >> base;

            std::cout << "Triangle height: ";
            std::cin >> height;

            area = (base * height) / 2;

            std::cout << "Area: " << area << std::endl;
            
            break;

        case 4:
            std::cout << "Bye!" << std::endl;

            break;

        default:
            std::cout << "You must choose a number between 1 and 4" << std::endl;

            break;
    }

    return 0;
}