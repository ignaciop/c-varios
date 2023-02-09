#include "Pascal.h"
#include <iostream>
#include <cassert>

Pascal::Pascal() : Pascal(1) {}

Pascal::Pascal(int iN) : n(iN) {
    if (n < 1) {
        std::cout << "Cannot calculate coefficients with n = 0." << std::endl;
        std::cout << "The program will terminate." << std::endl;

        assert(false);
    } else {
        pascal = new int* [n + 1];

        for (int i = 0; i < n + 1; i++) {
            pascal[i] = new int[i];
        }

        // Formation of the coefficient
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || i == j) {
                    pascal[i][j] = 1;
                } else {
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal [i - 1][j];
                }
            }
        }

        std::cout << "Coefficients for (x + y)^" << n << " are: ";

        for (int j = 0; j <= n; j++) {
            std::cout << pascal[n][j] << " ";
        }

        std::cout << '\n';
    }
}
        
Pascal::Pascal(const Pascal& pascalCopy) : n(pascalCopy.n), pascal(new int* [n + 1]) {
    for (int i = 0; i < n + 1; i++) {
        pascal[i] = new int[i];
    }

    for (int i = 0; i < n + 1; i++) {
        //copy each member of arrayToCopy into object
        pascal[i] = pascalCopy.pascal[i];
    }
}

Pascal::~Pascal() {
    for (int i = 0; i < n + 1; i++) {
        delete[] pascal[i];
    }

    delete[] pascal;
}