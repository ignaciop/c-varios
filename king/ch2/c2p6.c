#include <stdio.h>

int main(void) {
    float x = 0.0f;
    
    printf("Enter a value for x: ");
    scanf("%f", &x);

    float px = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

    printf("p(x) = 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 at x = %.2f is %.2f\n", x, px);

    return 0;
}