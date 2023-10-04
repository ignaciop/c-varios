#include <stdio.h>

float minimum2(float f, float g);
float minimum4(float f, float g, float h, float i);
float maximum2(float f, float g);
float maximum4(float f, float g, float h, float i);
float sum(float f, float g, float h, float i);

int main(void) {
    float f1 = 0.0f, f2 = 0.0f, f3 = 0.0f, f4 = 0.0f;

    printf("Give four floats: ");
    scanf("%f %f %f %f", &f1, &f2, &f3, &f4);

    float min = minimum4(f1, f2, f3, f4);
    float max = maximum4(f1, f2, f3, f4);
    float s = sum(f1, f2, f3, f4);
    float mean = s / 4;

    printf("min: %f\nmax: %f\nsum: %f\nmean: %f\n", min, max, s, mean);

    return 0;
}

float minimum2(float f, float g) {
    return ((f <= g) ? f : g);
}

float minimum4(float f, float g, float h, float i) {
    return minimum2(minimum2(f, g), minimum2(h, i));
}

float maximum2(float f, float g) {
    return ((f >= g) ? f : g);
}

float maximum4(float f, float g, float h, float i) {
    return maximum2(maximum2(f, g), maximum2(h, i));
}

float sum(float f, float g, float h, float i) {
    return (f + g + h + i);
}