#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Number of males registered in class: ";
    int males = 0;
    std::cin >> males;

    std::cout << "Number of females registered in class: ";
    int females = 0;
    std::cin >> females;

    int total = males + females;
    double males_percentage = (static_cast<double>(males) / total) * 100;
    double females_percentage = (static_cast<double>(females) / total) * 100;

    std::cout << "Males: " << std::fixed << std::setprecision(2)
                << males_percentage << "%" << std::endl;
    std::cout << "Females: " << std::fixed << females_percentage << "%" << std::endl;

    return 0;
}