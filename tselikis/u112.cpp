#include <iostream>

const float * two_pointers(const float *a, const float *b);

int main() {
    std::cout << "Enter first float: ";
    float a;
    std::cin >> a;

    std::cout << "Enter second float: ";
    float b;
    std::cin >> b;

    float *p_a = &a;
    float *p_b = &b;
    const float *res = two_pointers(p_a, p_b);

    std::cout << "Address: " << res << ", value: " << *res << std::endl;
   
    return 0;
}

const float * two_pointers(const float *a, const float *b) {
    const float *p = ((*a > *b) ? a : b);

    return p;
}