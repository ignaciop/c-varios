#include <stdio.h>

int main(void) {
    int day = 0, month = 0, year = 0;

    // Input the date
    printf("%s", "Enter the date (day month year): ");
    scanf("%d %d %d", &day, &month, &year);

    // Check for a valid date
    if (day <= 0 || month <= 0 || month > 12 || year <= 0) {
        printf("%s\n","Invalid date!");

        return 1;
    }

    // Check for the last day of the month
    int lastDay = 0;

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            lastDay = 29;  // Leap year
        } else {
            lastDay = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        lastDay = 30;
    } else {
        lastDay = 31;
    }

    // Check for a valid day
    if (day < 1 || day > lastDay) {
        printf("%s\n", "Invalid day for the given month!");
        return 1;
    }

    // Calculate the date of the following day
    day++;

    if (day > lastDay) {
        day = 1;
        month++;

        if (month > 12) {
            month = 1;
            year++;
        }
    }

    // Print the result
    printf("Date following %02d:%02d:%04d is %02d:%02d:%04d\n", day - 1, month, year, day, month, year);

    return 0;
}