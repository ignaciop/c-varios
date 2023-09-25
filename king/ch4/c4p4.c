#include <stdio.h>

int main(void) {
    int input, d1, d2, d3, d4, d5;

    printf("\nEnter a number between 0 and 32767: ");
    scanf("%d", &input);

    d5 = input % 8;
    input /= 8;

    d4 = input % 8;
    input /= 8;

    d3 = input % 8;
    input /= 8;

    d2 = input % 8;
    input /= 8;

    d1 = input % 8;
    
    printf("In octal, your number is: %1d%1d%1d%1d%1d\n\n", d1, d2, d3, d4, d5);
    
    return 0;
}