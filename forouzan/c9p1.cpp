#include <iostream>

void largest_of_two(int& n1, int& n2);
void largest_of_three(int& n1, int& n2, int& n3);
int& larger_of_two(int& n1, int& n2);
int& larger_of_three(int& n1, int& n2, int& n3);

int main() {
    int a = 5, b = 10, c = 15;
    int d = 6, e = 8, f = 7;

    largest_of_three(a, b, c);

    std::cout << "Pass-by-reference: the largest of three integers is: " << a << std::endl;

    int z = larger_of_three(d, e, f);

    std::cout << "Return-by-reference: the largest of three integers is: " << z << std::endl;

    return 0;
}

void largest_of_two(int& n1, int& n2) {
    if (n1 < n2) {
        n1 = n2;
    }
}

void largest_of_three(int& n1, int& n2, int& n3) {
    largest_of_two(n1, n2);
    largest_of_two(n1, n3);
}

int& larger_of_two(int& n1, int& n2) {
    if (n1 < n2) {
        return n2;
    }

    return n1;
}

int& larger_of_three(int& n1, int& n2, int& n3) {
    int m1 = larger_of_two(n1, n2);

    return larger_of_two(m1, n3);
}