#include <stdio.h>

int var = 2;

void print_var(void);

int main(void) {
    print_var(); 

    return 0;
}

void print_var(void) {
    extern int var;

    printf("x = %d\n", var);
}