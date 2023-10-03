#include <stdio.h>

void print_menu(void);
void do_operation(int choice);

int main(void) {
    int choice = 0;

    while (1) {
        print_menu();

        scanf("%d", &choice);

        if (choice != 5) {
            do_operation(choice);
        } else {
            break;
        }
    }
    
    return 0;
}

void print_menu(void) {
    printf("Simple Calculator\n");
    printf("1. Addition\n");
    printf("2. Substraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Quit\n");
}

void do_operation(int choice) {
    int a = 0, b = 0;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    switch (choice) {
    case 1:
        printf("%d + %d = %d\n", a, b, a + b);
        break;
    case 2:
        printf("%d - %d = %d\n", a, b, a - b);
        break;
    case 3:
        printf("%d * %d = %d\n", a, b, a * b);
        break;
    case 4:
        if (b == 0) {
            printf("Division by zero.\n");
        } else {
            printf("%d / %d = %d\n", a, b, a / b);
        }
        break;
    default:
        break;
    }
}