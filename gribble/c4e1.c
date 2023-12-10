#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0) {
            printf("%s", "Fizz");
        }
        
        if (i % 5 == 0) {
            printf("%s", "Buzz");
        }
                
        if ((i % 3 != 0) && (i % 5 != 0)) {
            printf("%d", i);
        }
        
        printf("\n");
    }
    
    return 0;
}