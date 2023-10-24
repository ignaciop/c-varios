#include <stdio.h>

int main(void) {
    double n = 0.0;

    printf("Enter number %d: ", 1);
    scanf("%lf", &n);

    double max = n, min = n;

    for (int i = 2; i <= 10; i++) {
        printf("Enter number %d: ", i);

        scanf("%lf", &n);
        
        if (n > max) {
            max = n;
        }
        
        if (n < min) {
            min = n;
        }
    }

    printf("Largest number is: %lf\n", max);
    printf("Smallest number is: %lf\n", min);

    return 0;
}