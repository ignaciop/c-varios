#include <stdio.h>

#define PI 3.1415f

int main(void) {
    float radius = 0.0f;
    
    printf("Enter the sphere radius: ");
    scanf("%f", &radius);

    float volume = 4.0f / 3.0f * PI * radius * radius * radius;

    printf("Volume of sphere of radius %.1f m: %.2f m^3\n", radius, volume);

    return 0;
}