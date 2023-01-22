#include <iostream>

int main() {
    int total_height_inches = 75;
    int feets = total_height_inches / 12;
    int inches = total_height_inches % 12;

    std::cout << total_height_inches << " inches is " << feets << " feet, "
                << inches << " inches." << std::endl;

    return 0;
}