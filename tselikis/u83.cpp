#include <iostream>
#include <cmath>

int main() {
    double d = 0.0;
    double *ptr = &d;

    std::cout << "Enter a double number: ";
    std::cin >> *ptr;

    *ptr = fabs(*ptr - static_cast<int>(*ptr));

    std::cout << "Fractional part: " << *ptr << std::endl;

    return 0;
}