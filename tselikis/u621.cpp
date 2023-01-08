#include <iostream>

int main() {
    int n = 1;

    do {
        std::cout << "Enter an odd number >= 3: ";
        std::cin >> n;
    } while ((n < 3) || (n % 2 == 0));

    float i = 1.0;
    float j = 3.0;
    float sum = 0.0;
    float div = 0.0;

    while (i < n) {
        div = 1 / (i * j);
        sum += div;

        i = j;
        j += 2;
    }

    std::cout << "Sum: " << sum << std::endl;
    
    return 0;
}