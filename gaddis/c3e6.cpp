#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Enter five test scores (separated by a space): ";
    double s1, s2, s3, s4, s5 = 0.0;
    std::cin >> s1 >> s3 >> s3 >> s4 >> s5;

    double avg = (s1 + s2 + s3 + s4 + s5) / 5;

    std::cout << "Average score: " << std::fixed << std::setprecision(1)
                << avg << std::endl;

    return 0;
}