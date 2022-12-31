#include <iostream>

int main() {
    std::cout << "Enter grade: " << std::endl;
    float grade = 0.0;
    std::cin >> grade;

    if ( grade >= 0 && grade < 10) {
        std::cout << "Need Help" << std::endl;
    } else if (grade >= 10 && grade <= 13) {
        std::cout << "Dangerous Zone" << std::endl;
    } else if (grade > 13 && grade <= 16) {
        std::cout << "Good" << std::endl;
    } else if (grade > 16 && grade <= 18) {
        std::cout << "Very Good" << std::endl;
    } else if (grade > 18 && grade <= 20) {
        std::cout << "Excellent" << std::endl;
    } else {
        std::cout << "Not a valid grade!" << std::endl;
    }

    return 0;
}