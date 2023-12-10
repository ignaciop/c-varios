#include <stdio.h>

int main(void) {
    double x2 = 612.0;
    double x0 = 10.0;
    double xi = 0.0;

    for (int i = 0; i < 5; i++) {
        xi = x0 - (((x0 * x0) - x2) / (2 * x0));
        
        printf("x%d = %.12f, x%d = %.12f\n", i, x0, i + 1, xi);
        
        x0 = xi;
    }
    
    return 0;
}