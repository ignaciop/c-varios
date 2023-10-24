#include <stdio.h>

int main(void) {
    float celsius = 0.0f;

    printf("%s", "Enter degrees Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = (celsius * 9.0f / 5.0f) + 32;

    printf("%.1f degrees Celsius converts to %.1f degrees Fahrenheit\n", celsius, fahrenheit);

    return 0;
}