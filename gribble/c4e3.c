#include <stdio.h>

int main(void) {
    int n = 6;
  
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (n - i); j++) { 
            printf(" ");
        }
    
        for (int j = (n - i); j < (n - i) + ((2 * i) - 1); j++) {
            printf("*");
        }
        
        printf("\n");
    }
    
    return 0;
}