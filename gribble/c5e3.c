#include <stdio.h>

int isprime(int n);

int main(void) {
    int j = 1;
    int i = 1;
    
    while (j <= 1000) {
        if (isprime(i) == 1) {
            printf("%d: %d\n", j, i);
                
            j++;
        }
        
        i++;
    }
    
    return 0;
}

int isprime(int n) {
    if (n <= 1) {
        return 0;
    }
    
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    
    return 1;
}