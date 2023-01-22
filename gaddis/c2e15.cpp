#include <iostream>

int main() {
    int minutes_lvl1 = 78;
    int minutes_lvl2 = 144;

    int hours_lvl1 = minutes_lvl1 / 60;
    int minutess_lvl1 = minutes_lvl1 % 60;

    int hours_lvl2 = minutes_lvl2 / 60;
    int minutess_lvl2 = minutes_lvl2 % 60;

    std::cout << "Level 1 completed in " << hours_lvl1 << " hours and "
                << minutess_lvl1 << " minutes." << std::endl;

    std::cout << "Level 2 completed in " << hours_lvl2 << " hours and "
                << minutess_lvl2 << " minutes." << std::endl;

    int hours_diff = (minutes_lvl2 - minutes_lvl1) / 60;
    int minutess_diff = (minutes_lvl2 - minutes_lvl1) % 60;

    std::cout << "Level 2 took " << hours_diff << " hours and " << minutess_diff
                << " minutes more than Level 1." << std::endl;

    return 0;
}