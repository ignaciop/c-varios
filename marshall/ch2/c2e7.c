#include <stdio.h>

int main(void) {
    const float PI = 3.14159f;
    
    float radius = 0.0f;

    printf("%s", "Circle radius? ");
    scanf("%f", &radius);

    if (radius < 0.0f) {
        printf("%s\n", "Error: Negative values not permitted.");

        return 1;
    }

    printf("The area of a circle of radius %.2f units is %.2f units\n", radius, PI * radius * radius);

    return 0;
}