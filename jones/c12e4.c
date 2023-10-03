#include <stdio.h>

void print_var(int x);

int main(void) {
    int var = 2;

    print_var(var); 

    return 0;
}

void print_var(int x) {
    printf("x = %d\n", x);
}