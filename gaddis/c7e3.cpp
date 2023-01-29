#include <iostream>
#include "classes/Widgets.h"

int main() {
    Widgets order;

    int num = 0;

    do {
        std::cout << "How many widgets have been ordered? ";
		std::cin >> num;
    } while (num < 0);

    order.numOfDays(num);

    return 0;
}