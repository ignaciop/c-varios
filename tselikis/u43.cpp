#include <iostream>

int main() {
    std::cout << "Enter minimum score to pass: ";
    float min_score;
    std::cin >> min_score;

    std::cout << "Enter grades of three students (<= 10): ";
    float g1, g2, g3;
    std::cin >> g1 >> g2 >> g3;

    int total_passed = (g1 >= min_score) + (g2 >= min_score) + (g3 >= min_score);

    std::cout << "Students success: " << total_passed << std::endl;

    return 0;
}