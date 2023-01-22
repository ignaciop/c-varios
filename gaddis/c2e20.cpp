#include <iostream>

int main() {
    double sqf_cover_per_gallon = 340.0F;
    double sqf_fence = 6.0F * 100.0F;
    double total_paint = 4.0F * sqf_fence;
    double total_gallons = total_paint / sqf_cover_per_gallon;

    std::cout << "It will require " << total_gallons << " gallons to paint 2 coats on each side of a fence of "
                << sqf_fence << " square feet, painting " << sqf_cover_per_gallon
                    << " feet per gallon." << std::endl;

    return 0;
}