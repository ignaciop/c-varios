#include <iostream>
#include "classes/Date.h"

int main() {
    int evMonth;	// local variable for month
	int evDay;		// local variable for day
	int evYear;		// local variable for year

	do {
		std::cout << "Enter the month number: ";
		std::cin >> evMonth;
	} while (evMonth > 12 || evMonth < 1);

	do {
		std::cout << "Enter the Day number: ";
		std::cin >> evDay;
	} while (evDay < 1 || evDay > 31);

	std::cout << "Enter the year number: ";
	std::cin >> evYear;

	Date myEvent(evDay, evMonth, evYear);	

	std::cout << "\n\tThe date of your event is:\n";
	myEvent.printShortDate();
	myEvent.printLongDate();
	myEvent.printLongDate2();

    Date myEvent2;

    std::cout << "\n\tThe date of your default event is:\n";
	myEvent2.printShortDate();
	myEvent2.printLongDate();
	myEvent2.printLongDate2();

    return 0;
}
