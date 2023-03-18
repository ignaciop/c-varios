#include <iostream>

int max_two(int a, int b);

int main() {
    std::cout << "Enter two integer numbers: ";
    int a {}, b {};
    std::cin >> a >> b;

    std::cout << "Max: " << max_two(a, b) << std::endl;

    return 0;
}

int max_two(int a, int b) {
    return ((a > b) ? a : b);
}