#include <iostream>

int main() {
    // Extraneous convoluted code to do what the exercise asked
    // "Do not use more than three variables....."

    std::cout << "Enter the lab grade of the first student: ";
    float l = 0.0;
    std::cin >> l;

    std::cout << "Enter the theory grade of the first student: ";
    float t = 0.0;
    std::cin >> t;
    std::cout << std::endl;

    int count = 0;

    if ((l * 0.3 + t * 0.7 >= 8) && (l * 0.3 + t * 0.7 <= 10)) {
        count++;
    }

    std::cout << "Enter the lab grade of the second student: ";
    std::cin >> l;

    std::cout << "Enter the theory grade of the second student: ";
    std::cin >> t;
    std::cout << std::endl;

    if ((l * 0.3 + t * 0.7 >= 8) && (l * 0.3 + t * 0.7 <= 10)) {
        count++;
    }

    std::cout << "Enter the lab grade of the third student: ";
    std::cin >> l;

    std::cout << "Enter the theory grade of the third student: ";
    std::cin >> t;
    std::cout << std::endl;

    if ((l * 0.3 + t * 0.7 >= 8) && (l * 0.3 + t * 0.7 <= 10)) {
        count++;
    }
    
    std::cout << "Total grades between 8 and 10: " << count << std::endl;

    return 0;
}