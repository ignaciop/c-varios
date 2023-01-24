#include <iostream>

int main() {
    std::cout << "Enter the wavelength (meters): ";
    double lambda = 0.0;
    std::cin >> lambda;

    if (lambda < 1e-11) {
        std::cout << "You have Gamma Rays" << std::endl;
    } else if (lambda > 1e-11 && lambda <= 1e-8) {
        std::cout << "You have X-Rays" << std::endl;
    } else if (lambda > 1e-8 && lambda <= 4e-7) {
        std::cout << "You have Ultraviolet" << std::endl;
    } else if (lambda > 4e-7 && lambda <= 7e-7) {
        std::cout << "You have Visible Light" << std::endl;
    } else if (lambda > 7e-7 && lambda <= 1e-3) {
        std::cout << "You have Infrared" << std::endl;
    } else if (lambda > 1e-3 && lambda <= 1e-2) {
        std::cout << "You have Microwaves" << std::endl;
    } else {
        std::cout << "You have Radio Waves" << std::endl;
    }
    
    return 0;
}