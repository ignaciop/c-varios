#include <iostream>

int main() {
    std::cout << "Enter minimum score to pass: ";
    float min_score;
    std::cin >> min_score;

    std::cout << "Enter grades of three students (<= 10): ";
    float g1, g2, g3;
    std::cin >> g1 >> g2 >> g3;

    int total_passed = (g1 >= min_score) + (g2 >= min_score) + (g3 >= min_score);
    float avg = ((g1 >= min_score) * g1 + (g2 >= min_score) * g2 + (g3 >= min_score) * g3) / total_passed;

    std::cout << "Students success: " << total_passed << std::endl;
    std::cout << "Average of passed: " << avg << std::endl;

    return 0;
}