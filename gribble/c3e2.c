#include <stdio.h>
#include <math.h>

int main(void) {
    double a = 1.2;
    double b = 2.3;
    double c = -3.4;
    
    double x1 = -b + sqrt(b * b - 4 * a * c);
    double x2 = -b - sqrt(b * b - 4 * a * c);
    
    printf("Roots of %.1f * x^2 + %.1f * x + %.1f are %.5f and %.5f\n", a, b, c,
            x1, x2);
    
    return 0;
}