#include <iostream>
#include <iomanip>
#include <cmath>

double pi(int n);

int main () {
    for (int i = 1; i <= 2001; i += 200) {
        std::cout << "i = " << std::setw(4) << i << ": Pi = ";

        std::cout << pi(i) << std::endl;
    }
    
    return 0;
}

double pi(int n) {
    double pie = 0.0;

    for (int i = 1; i <= n; i++) {
        pie += pow(-1, i + 1) / (2 * i - 1);
    }

    return (4 * pie);
}