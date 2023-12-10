#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("%s\n", "Usage: ./c6e3 X, where X is a natural number (>= 0)");
        
        return 1;
    }
    
    int n = atoi(argv[1]);    
    
    printf("fib(%d) = %d\n", n, fib(n));
      
    return 0;
}

int fib(int n) {
    int x = 0;
    int y = 1;
    int i = 1; 
    
    while (i < n) {
        int temp = y;
        
        y = x + y;
        x = temp;
        
        i++;
    }
    
    return y;
}