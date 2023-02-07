#include <iostream>
#include <cmath>

int countDigits(int n);
int reverse(int n);
bool isPalindrome(int n);

int main () {
    std::cout << "Enter an integer: ";
    int n = 0;
    std::cin >> n;

    if (isPalindrome(n)) {
        std::cout << n << " is a palindrome." << std::endl;
    } else {
        std::cout << n << " is not a palindrome." << std::endl;
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

bool isPalindrome(int n) {
    return (n == reverse(n));
}