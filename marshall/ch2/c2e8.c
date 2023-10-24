#include <stdio.h>

int main(void) {
    const float CENT_TO_INCH = 2.54f;
    const int INCH_TO_FOOT = 12;

    float centimeters = 0.0f;

    printf("%s", "Centimeters: ");
    scanf("%f", &centimeters);

    float total_inches = centimeters / CENT_TO_INCH;

    int feet = (int)total_inches / INCH_TO_FOOT;
    float inches = total_inches - feet * INCH_TO_FOOT;

    printf("%.1f centimeters is %d feet %1.f inches\n", centimeters, feet, inches);

    return 0;
}