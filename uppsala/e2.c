#include <stdio.h>

void sum_two_integers(int a, int b);
void multiply_two_floats(float f, float g);
void show_word(char word[]); 

int main(void) {
    int a = 0, b = 0;
    float f = 0.0f, g = 0.0f;
    char word[100] = {'0'};

    printf("Give two integers: ");
    scanf("%d %d", &a, &b);
    sum_two_integers(a, b);

    printf("Give two floats: ");
    scanf("%f %f", &f, &g);
    multiply_two_floats(f, g);

    printf("Give a word: ");
    scanf("%s", word);
    show_word(word);

    return 0;
}

void sum_two_integers(int a, int b) {
    printf("You entered %d and %d, their sum is: %d\n", a, b, a + b);
}

void multiply_two_floats(float f, float g) {
    printf("You entered %f and %f, their product is: %f\n", f, g, f * g);
}

void show_word(char word[]) {
    printf("%s %s\n", word, word);
}