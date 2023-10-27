#include <stdio.h>
#include <time.h>

int main(void) {
    time_t biggest = 0x7FFFFFFF;
    
    printf("biggest = %s \n", asctime(gmtime(&biggest)));

    time_t current = time(NULL);

    double seconds_diff = difftime(biggest, current);

    // Calculate years, months, weeks, days, hours, and minutes
    int secondsInMinute = 60;
    int secondsInHour = secondsInMinute * 60;
    int secondsInDay = secondsInHour * 24;
    int secondsInWeek = secondsInDay * 7;
    int secondsInMonth = secondsInDay * 30; // Approximation for a month
    int secondsInYear = secondsInDay * 365; // Approximation for a year

    int years = seconds_diff / secondsInYear;
    seconds_diff -= years * secondsInYear;

    int months = seconds_diff / secondsInMonth;
    seconds_diff -= months * secondsInMonth;

    int weeks = seconds_diff / secondsInWeek;
    seconds_diff -= weeks * secondsInWeek;

    int days = seconds_diff / secondsInDay;
    seconds_diff -= days * secondsInDay;

    int hours = seconds_diff / secondsInHour;
    seconds_diff -= hours * secondsInHour;

    int minutes = seconds_diff / secondsInMinute;
    seconds_diff -= minutes * secondsInMinute;

    // Print the result
    printf("Years: %d\n", years);
    printf("Months: %d\n", months);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d\n", days);
    printf("Hours: %d\n", hours);
    printf("Minutes: %d\n", minutes);

    return 0;
}