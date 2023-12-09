#include <stdio.h>

int main(void) {
    float fahrenheit = 27.0F;
    float celsius = (fahrenheit - 32.0F) / 1.8F;
    
    printf("%.1fºF is %.1fºC\n", fahrenheit, celsius);
    
    return 0;
}