#include <iostream>

bool isPrime(int n);

int main() {
    int n = 2;

    do {
        std::cout << "Enter an integer number >= 2: ";
        std::cin >> n;
    } while (n < 2);

    std::cout << n << ((isPrime(n)) ? " is prime." : " is not prime.") << std::endl;    
    
    return 0;
}
  
bool isPrime(int n) {
    bool prime = true;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            prime = !prime;
            break;
        }
    }

    return prime;
}