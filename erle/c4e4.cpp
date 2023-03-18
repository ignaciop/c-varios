#include <iostream>

int sumUpTo(int n);

int main() {
    std::cout << "Enter an integer number: ";
    int n {};
    std::cin >> n;

    std::cout << "Sum from 1 to " << n << " = " << sumUpTo(n) << std::endl;;

    return 0;
}

int sumUpTo(int n) {
    int sum {0};

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}