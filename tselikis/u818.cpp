#include <iostream>

int main() {
    int i = 0;
    int j = 0;

    int *p1 = &i;
    int *p2 = &j;

    int **pp1 = &p1;
    int **pp2 = &p2;

    std::cout << "First integer: ";
    std::cin >> **pp1;

    std::cout << "Second integer: ";
    std::cin >> **pp2;

    std::cout << "Before swap: i = " << **pp1 << ", j = " << **pp2 << std::endl;

    pp1 = &p2;
    pp2 = &p1;

    std::cout << "After swap: i = " << **pp1 << ", j = " << **pp2 << std::endl;
 
    return 0;
}