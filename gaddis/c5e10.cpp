#include <iostream>

int main() {
    const double CALORIES_PER_MINUTE = 3.9F;

    double calories_burned = 0.0;

    for (int i = 5; i <= 30; i += 5) {
        calories_burned = i * CALORIES_PER_MINUTE;

        std::cout << "Calories burned after " << i << " minutes = " 
                    << calories_burned << std::endl;
    }

    return 0;
}