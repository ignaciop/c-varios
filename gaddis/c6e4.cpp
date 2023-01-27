#include <iostream>

double kineticEnergy(double mass, double velocity);

int main() {
    std::cout << "Enter the object mass: ";
    double mass = 0.0;
    std::cin >> mass;

    std::cout << "Enter the object velocity: ";
    double velocity = 0.0;
    std::cin >> velocity;

    std::cout << "Kinetic energy: " << kineticEnergy(mass, velocity) << " J." << std::endl;

    return 0;
}

double kineticEnergy(double mass, double velocity) {
    return (0.5 * mass * velocity * velocity);
}