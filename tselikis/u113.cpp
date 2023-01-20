#include <iostream>

int f(int x);
int g(int x);

int main() {
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;

    int res = f(x);

    std::cout << "f(g(" << x << ")) = " << res << std::endl;
   
    return 0;
}

int f(int x) {
    if (x > 0) {
        return (g(x) + 2);
    } else {
        return (-3 * g(x) + 7);
    }
}

int g(int x) {
    if (x > 0) {
        return (x * x + 2);
    } else {
        return (7 * x - 5);
    }
}