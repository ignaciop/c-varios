#include <iostream>

int main() {
    std::cout << "Enter grade: " << std::endl;
    float grade = 0.0;
    std::cin >> grade;

    std::cout << (( grade >= 0 && grade < 10) ? "Need Help" : ((grade >= 10 && grade <= 13) ? "Dangerous Zone" : ((grade > 13 && grade <= 16) ? "Good" : ((grade > 16 && grade <= 18) ? "Very Good" : ((grade > 18 && grade <= 20) ? "Excellent" : "Not a valid grade!"))))) 
                << std::endl;

    return 0;
}