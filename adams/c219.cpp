#include <iostream>

void swap(int *p, int *q);
void swap(int &r, int &s);

int main() {
    std::cout << "Enter a number: ";
    int a = 0;
    std::cin >> a;

    std::cout << "Enter a number: ";
    int b = 0;
    std::cin >> b;

    int *p_a = &a;
    int *p_b = &b;

    std::cout << "Before swap with pointer version..." << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    swap(p_a, p_b);

    std::cout << "After swap with pointer version..." << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "\nBefore swap with reference version..." << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    swap(&a, &b);

    std::cout << "After swap with reference version..." << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}

void swap(int *p, int *q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void swap(int &r, int &s) {
    int pSwap = r;
    r = s;
    s = pSwap;
}