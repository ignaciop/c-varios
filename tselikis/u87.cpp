#include <iostream>

int main() {
    int i, j, k = 0;
    int *ptr1 = &i;
    int *ptr2 = &j;
    int *ptr3 = &k;

    std::cout << "Enter first integer number: ";
    std::cin >> *ptr1;

    do {
    std::cout << "Enter second integer number less than the first: ";
    std::cin >> *ptr2;
    } while (*ptr2 >= *ptr1);

    do {
        std::cout << "Enter third integer number less than the second: ";
        std::cin >> *ptr3;
    } while (*ptr3 >= *ptr2);

    std::cout << *ptr1 << " > " << *ptr2 << " > " << *ptr3 << std::endl;

    return 0;
}