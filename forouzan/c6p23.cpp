#include <iostream>
#include <cmath>

int countDigits(int n);
int reverse(int n);

int main () {
    for (int i = 1; i <= 250; i += 25) {
        std::cout << "Number: " << i << " --> Reverse: " << reverse(i) << std::endl;
    }
    
    return 0;
}

int countDigits(int n) {
    int count = 0;

    int t = n;

    while (t != 0) {
        count++;

        t /= 10;
    }

    return count;
}

int reverse(int n) {
    int reverse = 0;

    int t = n;

    int digits = countDigits(n);

    while (t != 0) {
        reverse += (t % 10) * pow(10, digits - 1);

        t /= 10;
        digits--;
    }

    return reverse;
}