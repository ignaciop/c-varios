#include "Widgets.h"
#include <iostream>

void Widgets::numOfDays(int order) {
    const int widgets_per_day = widgets_per_hour * work_hours_per_day;

    int days = 0;

    if (order <= widgets_per_day) {
        days = 1;
    } else if (order % widgets_per_day == 0) {
        days = order / widgets_per_day;
    } else {
        days = (order / widgets_per_day) + 1;
    }

    std::cout << "Number of days to produce " << order << " widgets: "
                << days << std::endl;
}