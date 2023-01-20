#include <iostream>
#include <vector>
#include <cmath>

double poly(const std::vector<double>& a, double x, int n);

int main() {
    int n = 0;
    double x = 0.0;

    std::vector<double> a = {};

    do {
    std::cout << "Enter degree of polynomial: ";
    std::cin >> n;
    } while (n >= 100);

    for (int i = 0; i <= n; i++) {
        std::cout << "Enter coefficient a_" << i << ": ";
        double coeff = 0.0;
        std::cin >> coeff;

        a.push_back(coeff);
    }

    std::cout << "Enter a value: ";
    std::cin >> x;

    double res = poly(a, x, n);

    std::cout << "p(" << x << ") = " << res << std::endl;
    
    return 0;
}

double poly(const std::vector<double>& a, double x, int n) {
    double pol_eval_x = 0.0;

    for (auto it = a.begin(); it != a.end(); it++) {
        double num = *it * pow(x, it - a.begin());
        pol_eval_x += num;
    }

    return pol_eval_x;
}