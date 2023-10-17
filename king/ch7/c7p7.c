#include <stdio.h>

int main(void) {
    int num1 = 0, denom1 = 1, num2 = 0, denom2 = 1, result_num = 0, result_denom = 1;
    char op = ' ';

    printf("Enter two fractions separated by a +, -, * or /: ");
    scanf("%d/%d %c %d/%d", &num1, &denom1, &op, &num2, &denom2);

    if (denom1 == 0 || denom2 == 0) {
        printf("The denominators cannot be zero. Please run again the program with another values.\n");

        return 0;
    }
     
    switch (op) {
    case '+':
        result_num = num1 * denom2 + num2 * denom1;
        result_denom = denom1 * denom2;
        break;
    case '-':
        result_num = num1 * denom2 - num2 * denom1;
        result_denom = denom1 * denom2;
        break;
    case '*':
        result_num = num1 * num2;
        result_denom = denom1 * denom2;
        break;
    case '/':
        result_num = num1 * denom2;
        result_denom = denom1 * num2;
        break;
    default:
        printf("Please enter a valid operation and run again the program.\n");

        return 0;
        break;
    }
    
    int m = result_num, n = result_denom;

    while (n != 0) {
        int rem = m % n;
        m = n;
        n = rem;
    }

    int red_num = result_num / m;
    int red_den = result_denom / m;

    printf("%d/%d %c %d/%d = %d/%d\n", num1, denom1, op, num2, denom2, red_num, red_den);

    return 0;
}