#include <stdio.h>

int main(void) {
    int width = 3;
    int height = 5;
    int area = width * height;
    int perimeter = 2 * (width + height);

    printf("Area of %d in. * %d in. rectangle: %d in^2\n", width, height, area);
    printf("Perimeter of %d in. * %d in. rectangle: %d in\n", width, height, perimeter);

    float f_width = 6.8f;
    float f_height = 2.3f;
    float f_area = width * height;
    float f_perimeter = 2 * (width + height);

    printf("Area of %f in. * %f in. rectangle: %f in^2\n", f_width, f_height, f_area);
    printf("Perimeter of %f in. * %f in. rectangle: %f in\n", f_width, f_height, f_perimeter);

    return 0;
}