#include <stdio.h>

#define RADIUS 10.0f
#define PI 3.1415f

int main(void) {
    float volume = 4.0f / 3.0f * PI * RADIUS * RADIUS * RADIUS;

    printf("Volume of sphere of radius %.1f m: %.2f m^3\n", RADIUS, volume);

    return 0;
}