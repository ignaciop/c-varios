#include <iostream>

int main() {
    int i, j, k = 0;
    int *ptr1 = &i;
    int *ptr2 = &j;
    int *ptr3 = &k;

    do {
        std::cout << "Enter a negative integer number: ";
        std::cin >> *ptr1;

        std::cout << "Enter a negative integer number: ";
        std::cin >> *ptr2;

        std::cout << "Enter a negative integer number: ";
        std::cin >> *ptr3;
    } while (*ptr1 >= 0 || *ptr2 >= 0 || *ptr3 >= 0);

    if (*ptr1 < *ptr2 && *ptr2 < *ptr3) {
        std::cout << "They are in succesive ascending order" << std::endl;
    } else {
        std::cout << "They are not in succesive ascending order" << std::endl;
    }

    return 0;
}