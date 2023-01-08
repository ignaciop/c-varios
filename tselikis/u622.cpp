#include <iostream>

int main() {
    STEP:
    std::cout << "Enter a positive integer < 20: ";
    int n = 1;
    std::cin >> n;

    if ((n <= 0 ) || (n >= 20)) {
        goto STEP;
    }

    int term = 0;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        term = 2 * i;
        sum += term * term;
    }
    
    std::cout << "Sum: " << sum << std::endl;
    
    return 0;
}