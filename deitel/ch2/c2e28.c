#include <stdio.h>

int main(void) {
    int age = 0;

    printf("%s", "Enter your age: ");
    scanf("%d", &age);

    int max_heart_rate = 220 - age;

    printf("Your target heart rate is between %f and %f bpm\n", max_heart_rate * 0.5f, max_heart_rate * 0.85f);
    
    return 0;
}