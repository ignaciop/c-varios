#include <iostream>

// At this point, the exercise do not ask to find gcd to reduce fractions, so...

int main() {
    std::cout << "Enter a numerator and denominator (!= 0): " << std::endl;
    int a, b;
    std::cin >> a >> b;

    std::cout << "Enter another numerator and denominator (!= 0): " << std::endl;
    int c, d;
    std::cin >> c >> d;

    if (b == 0 || d == 0) {
        std::cout << "Denominators should not be zero!!" << std::endl;
    } else {
        std::cout << "Select an operation: " << std::endl;
        std::cout << "1. Addition " << std::endl;
        std::cout << "2. Substraction " << std::endl;
        std::cout << "3. Multiplication " << std::endl;
        std::cout << "4. Division " << std::endl;
        int choice = 0;
        std::cin >> choice;

        int numerator_res = 0;
        int denominator_res = 1;

        switch (choice) {
            case 1:
                numerator_res = a * d + b * c;
                denominator_res = b * d;
                std::cout << a << "/" << b << " + " << c << "/" << d << " = "
                            << numerator_res << "/" << denominator_res << std::endl;
                break;
            case 2:
                numerator_res = a * d - b * c;
                denominator_res = b * d;
                std::cout << a << "/" << b << " - " << c << "/" << d << " = "
                            << numerator_res << "/" << denominator_res << std::endl;
                break;
            case 3:
                numerator_res = a * c;
                denominator_res = b * d;
                std::cout << a << "/" << b << " * " << c << "/" << d << " = "
                            << numerator_res << "/" << denominator_res << std::endl;
                break;
            case 4:
                numerator_res = a * d;
                denominator_res = b * c;
                std::cout << a << "/" << b << " / " << c << "/" << d << " = "
                            << numerator_res << "/" << denominator_res << std::endl;
                break;
        }
    }

    return 0;
}