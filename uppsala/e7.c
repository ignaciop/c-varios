#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int div(int a, int b);

int main(void) {
    int a = 0, b = 0;

    printf("Give a: ");
    scanf("%d", &a);

    printf("Give b: ");
    scanf("%d", &b);

    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d - %d = %d\n", a, b, sub(a, b));
    printf("%d * %d = %d\n", a, b, mult(a, b));
    
    if (b == 0) {
        printf("%d / %d = Error. Cannot divide by zero.\n", a, b);
    } else {
        printf("%d / %d = %d\n", a, b, div(a, b));
    }

    return 0;
}

int add(int a, int b) {
    return (a + b);
}

int sub(int a, int b) {
    return (a - b);
}

int mult(int a, int b) {
    return (a * b);
}

int div(int a, int b) {
    return (a / b);
}