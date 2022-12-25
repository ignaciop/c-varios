#include <iostream>

int main() {
    std::cout << "Enter number of students who passed and failed the exams: ";
    int p = 0, f = 0;
    std::cin >> p >> f;

    float total = p + f;
    float percentage_pass = (p * 100) / total;
    float percentage_failed = (f * 100) / total;

    std::cout << "Success Ratio: " << percentage_pass << "%" << std::endl;
    std::cout << "Fail Ratio: " << percentage_failed << "%" << std::endl;

    return 0;
}