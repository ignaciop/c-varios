#include <stdio.h>

void print40(void);
void print100(void);
void print_squared(void);

int main(void) {
    print40();
    print100();
    print_squared();

    return 0;
}

void print40(void) {
    int i = 0;

    printf("Even numbers between 0 and 40:\n");

    while (i <= 40) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }

        i++;
    }

    printf("\b\n");
}

void print100(void) {
    printf("Numbers 1 to 100:\n");
    
    for (int i = 1; i <= 100; i += 10) {
        for (int j = 0; j < 10; j++) {
            printf("%3d ", i + j);
        }

        printf("\n");
    }
}

void print_squared(void) {
    int number = 1;

    while (1) {
        printf("Give a number: ");
        scanf("%d", &number);

        if (number != 0) {
            printf("The square of %d is %d\n", number, number * number);
        } else {
            printf("You entered zero.\n");

            break;
        }
    }
}