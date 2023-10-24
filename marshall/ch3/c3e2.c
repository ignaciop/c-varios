#include <stdio.h>

int main(void) {
    int n = 0;

    printf("%s", "Enter the month number: ");
    scanf("%d", &n);

    switch (n) {
    case 1:
        printf("%d --> %s\n", n, "January");
        break;
    case 2:
        printf("%d --> %s\n", n, "February");
        break;
    case 3:
        printf("%d --> %s\n", n, "March");
        break;
    case 4:
        printf("%d --> %s\n", n, "April");
        break;
    case 5:
        printf("%d --> %s\n", n, "May");
        break;
    case 6:
        printf("%d --> %s\n", n, "June");
        break;
    case 7:
        printf("%d --> %s\n", n, "July");
        break;
    case 8:
        printf("%d --> %s\n", n, "August");
        break;
    case 9:
        printf("%d --> %s\n", n, "September");
        break;
    case 10:
        printf("%d --> %s\n", n, "October");
        break;
    case 11:
        printf("%d --> %s\n", n, "November");
        break;
    case 12:
        printf("%d --> %s\n", n, "December");
        break;
    default:
        printf("%s\n", "Please re-run the program and enter a number between 1 and 12");
        break;
    }
    
    return 0;
}