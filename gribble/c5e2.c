#include <stdio.h>

int isprime(int n);

int main(void) {
    printf("isprime(%d) = %d\n", 12, isprime(12));
    printf("isprime(%d) = %d\n", 17, isprime(17));
    
    return 0;
}

int isprime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    
    return 1;
}