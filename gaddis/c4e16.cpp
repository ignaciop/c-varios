#include <iostream>

int main() {
    std::cout << "Enter your weight (in pounds): ";
    double weight = 0.0;
    std::cin >> weight;

    std::cout << "Enter your height (in inches): ";
    double height = 0.0;
    std::cin >> height;

    double bmi = weight * 703 / (height * height);

    if (bmi < 18.5) {
        std::cout << "You are underweight" << std::endl;
    } else if (bmi >= 18.5 && bmi <= 25.0) {
        std::cout << "You have optimal weight" << std::endl;
    } else {
        std::cout << "You are overweight" << std::endl;
    }

    return 0;
}