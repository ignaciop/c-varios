#include <iostream>

int main() {
    int i = 50;
    int j = 20;

    std::cout << "Sum:" << i+j << "\nDiff:" << i-j << "\nProd:" << i*j <<
               "\nDiv:" << (double)i/j << "\nRem:" << i%j << '\n';

    return 0;
}