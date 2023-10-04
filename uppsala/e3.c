#include <stdio.h>

void zero_or_not(void);
void largest(void);
void parity(void);
void equals(void); 

int main(void) {
    zero_or_not();
    largest();
    parity();
    equals();

    return 0;
}

void zero_or_not(void) {
    int a = 0;

    printf("Give an integer: ");
    scanf("%d", &a);
    
    printf((a == 0) ? "The number you entered equals zero\n" : "The number you entered is not equal zero\n");
}

void largest(void) {
    float f = 0.0f, g = 0.0f;

    printf("Give two floats: ");
    scanf("%f %f", &f, &g);

    float max = (f >= g) ? f : g;

    printf("%f is the largest\n", max);
}

void parity(void) {
    int a = 0;

    printf("Give an integer: ");
    scanf("%d", &a);

    a = (a % 2 == 0) ? a / 2 : a * 3;

    printf("Result is: %d\n", a);
}

void equals(void) {
    int a = 0, b = 0, c = 0;

    printf("Give three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a != b && b != c && c != a) {
        printf("All are unique\n");
    } else {
        printf("Some numbers are equal\n");
    }
}