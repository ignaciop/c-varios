#include "Date.h"
#include <iostream>
#include <string>

Date::Date(int inputMonth, int inputDay, int inputYear) {
    month = inputMonth;
    day = inputDay;
    year = inputYear;
}

Date::~Date() {}

void Date::printShortDate() {
    std::cout << month << "/" << day << "/" << year << std::endl;
}

void Date::printLongDate() {
	std::string whatMonth;		

	switch (month) {
	    case 1:
		    whatMonth = "January";
		    break;
	    case 2:
		    whatMonth = "February";
		    break;
	    case 3:
		    whatMonth = "March";
		    break;
	    case 4:
		    whatMonth = "April";
		    break;
	    case 5:
		    whatMonth = "May";
		    break;
	    case 6:
		    whatMonth = "June";
		    break;
	    case 7:
		    whatMonth = "July";
		    break;
	    case 8:
		    whatMonth = "August";
		    break;
	    case 9:
		    whatMonth = "September";
		    break;
	    case 10:
		    whatMonth = "October";
		    break;
	    case 11:
		    whatMonth = "November";
		    break;
	    case 12:
		    whatMonth = "December";
		    break;
	}

	std::cout << whatMonth << " " << day << ", " << year << std::endl;
}

void Date::printLongDate2() {
	std::string whatMonth;		

	switch (month) {
	    case 1:
		    whatMonth = "January";
		    break;
	    case 2:
		    whatMonth = "February";
		    break;
	    case 3:
		    whatMonth = "March";
		    break;
	    case 4:
		    whatMonth = "April";
		    break;
	    case 5:
		    whatMonth = "May";
		    break;
	    case 6:
		    whatMonth = "June";
		    break;
	    case 7:
		    whatMonth = "July";
		    break;
	    case 8:
		    whatMonth = "August";
		    break;
	    case 9:
		    whatMonth = "September";
		    break;
	    case 10:
		    whatMonth = "October";
		    break;
	    case 11:
		    whatMonth = "November";
		    break;
	    case 12:
		    whatMonth = "December";
		    break;
	}

	std::cout << day << " " << whatMonth << " " << year << std::endl;
}