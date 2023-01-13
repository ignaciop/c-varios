#include <iostream>
#include <cmath>

int main() {
    double *ptr1, *ptr2, d1 = 0, d2 = 0;

    ptr1 = &d1;
    ptr2 = &d2;

    std::cout << "First double number: ";
    std::cin >> *ptr1;

    std::cout << "Second double number: ";
    std::cin >> *ptr2;

    std::cout << "|" << *ptr1 << " + " << *ptr2 << "| = "
                << fabs(*ptr1 + *ptr2) << std::endl;

    return 0;
}