#include <stdio.h>

int fib(int n);

int main(void) {
    printf("fib(%d) = %d\n", 10, fib(10));
      
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