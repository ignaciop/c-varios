#include <iostream>

int main() {
    const unsigned int TOUCHDOWN = 6;
    const unsigned int FIELD_GOAL = 3;
    const unsigned int POINT_AFTER_TOUCHDOWN = 1;
    const unsigned int SAFETY = 2;

    std::cout << "Total points in the game: " << TOUCHDOWN
                + FIELD_GOAL + POINT_AFTER_TOUCHDOWN + SAFETY << std::endl;
    
    return 0;
}