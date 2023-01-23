#include <iostream>

int main() {
    const double PI = 3.14F;
    const double SLICE_AREA = 14.125F;
    const int SLICES_PER_PERSON = 4;

    std::cout << "Enter the number of people: ";
    int people = 0;
    std::cin >> people;

    std::cout << "Enter the diameter of the pizza (in inches): ";
    double diameter = 0.0;
    std::cin >> diameter;

    double radius = diameter / 2;
    double area = PI * radius * radius;
    double slices_per_pizza = area / SLICE_AREA;

    int total_slices = SLICES_PER_PERSON * people;
    double pizzas = total_slices / slices_per_pizza;

    std::cout << "Number of pizzas: " << static_cast<int>(pizzas) << std::endl;
    
    return 0;
}