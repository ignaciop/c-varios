#include <stdio.h>

int main(void) {
    int number = 0;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    int ten_digit = number / 10;
    int unit_digit = number % 10;

    printf("You entered the number ");

    switch (ten_digit) {
    case 1:
        printf(" ");
        break;
    case 2:
        printf("twenty-");
        break;
    case 3:
        printf("thirty-");
        break;
    case 4:
        printf("forty-");
        break;
    case 5:
        printf("fifty-");
        break;
    case 6:
        printf("sixty-");
        break;
    case 7:
        printf("seventy-");
        break;
    case 8:
        printf("eighty-");
        break;
    case 9:
        printf("ninety-");
        break;
    default:
        break;
    }

    if (ten_digit == 1) {
        switch (unit_digit) {
        case 0:
            printf("\bten.\n");
            break;
        case 1:
            printf("\beleven.\n");
            break; 
        case 2:
            printf("\btwelve.\n");
            break;
        case 3:
            printf("\bthirteen.\n");
            break;
        case 4:
            printf("\bfourteen.\n");
            break;
        case 5:
            printf("\bfifteen.\n");
            break;
        case 6:
            printf("\bsixteen.\n");
            break;
        case 7:
            printf("\bseventeen.\n");
            break;
        case 8:
            printf("\beighteen.\n");
            break;
        case 9:
            printf("\bnineteen.\n");
            break;
        default:
            break;
        }
    } else {
        switch (unit_digit) {
        case 0:
            printf("\b.\n");
            break;
        case 1:
            printf("one.\n");
            break; 
        case 2:
            printf("two.\n");
            break;
        case 3:
            printf("three.\n");
            break;
        case 4:
            printf("four.\n");
            break;
        case 5:
            printf("five.\n");
            break;
        case 6:
            printf("six.\n");
            break;
        case 7:
            printf("seven.\n");
            break;
        case 8:
            printf("eight.\n");
            break;
        case 9:
            printf("nine.\n");
            break;
        default:
            break;
        }
    }

    return 0;
}