#include <iostream>

void compare_arrays(double a[], double b[], int elems, int * p_res);

int main() {
    const int ARRAY_SIZE = 100;
    double a[ARRAY_SIZE] = {};
    double b[ARRAY_SIZE] = {};
    int res = 0;
    int elems = 0;

    for (int i = 0; i < ARRAY_SIZE; i ++) {
        std::cout << "Enter number: ";
        std::cin >> a[i];
    }

    for (int i = 0; i < ARRAY_SIZE; i ++) {
        std::cout << "Enter number: ";
        std::cin >> b[i];
    }

    do {
        std::cout << "\nNumber of elements to be compared: ";
        
        std::cin >> elems;
    } while (elems < 0 || elems > ARRAY_SIZE);

    int * p_res = &res;

    compare_arrays(a, b, elems, p_res);

    if (*p_res == 1) {
        std::cout << "\nThe first " << elems << " elements are equal." << std::endl;
    } else {
        std::cout << "\nThe first " << elems << " elements are not equal." << std::endl;
    }

    return 0;
}

void compare_arrays(double a[], double b[], int elems, int * p_res) {
    for (int i = 0; i < elems; i++) {
        if (a[i] == b[i]) {
            *p_res = 1;
        } else {
            *p_res = 0;
            break;
        }
    }
}