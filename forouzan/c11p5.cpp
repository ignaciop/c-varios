#include <iostream>
#include "classes/Employee2.h"
#include "classes/SalariedEmployee.h"
#include "classes/HourlyEmployee.h"

int main() {
    SalariedEmployee se("John Doe", "1234", "1/1/1970", "3/2/1995", 1500.00, 5.5);

    HourlyEmployee he("Jane Doe", "4567", "1/1/1971", "4/2/1996", 180.50, 65.0);

    return 0;
}