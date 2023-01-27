#include <iostream>

double fallingDistance(double seconds);

int main() {
    for (int i = 1; i <= 10; i++) {
        std::cout << "Time: " << i << " s --> Distance: " << fallingDistance(i)
                    << " m." << std::endl; 
    }

    return 0;
}

double fallingDistance(double seconds) {
    const double G = 9.8F;

    return (0.5 * G * seconds * seconds);
}