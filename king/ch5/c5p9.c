#include <stdio.h>

int main(void) {
    int month1 = 0, day1 = 0, year1 = 0;
    int month2 = 0, day2 = 0, year2 = 0;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month1, &day1, &year1);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month2, &day2, &year2);

    if (year1 < year2) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month1, day1, year1, month2, day2, year2);
    } else if (year1 > year2) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month2, day2, year2, month1, day1, year1);
    } else {
        if (month1 < month2) {
            printf("%d/%d/%d is earlier than %d/%d/%d\n", month1, day1, year1, month2, day2, year2);
        } else if (month1 > month2) {
            printf("%d/%d/%d is earlier than %d/%d/%d\n", month2, day2, year2, month1, day1, year1);
        } else {
            if (day1 < day2) {
                printf("%d/%d/%d is earlier than %d/%d/%d\n", month1, day1, year1, month2, day2, year2);
            } else if (day1 > day2) {
                printf("%d/%d/%d is earlier than %d/%d/%d\n", month2, day2, year2, month1, day1, year1);
            } else {
                printf("The dates are equal.\n");
            }
        }
    }
    
    return 0;
}