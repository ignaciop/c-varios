#include <iostream>

int main() {
    const double WIDGET_WEIGHT = 12.5F;

    std::cout << "Enter the empty pallet weight: ";
    double empty_pallet_weight = 0.0;
    std::cin >> empty_pallet_weight;

    std::cout << "Enter the loaded pallet weight: ";
    double loaded_pallet_weight = 0.0;
    std::cin >> loaded_pallet_weight;

    int widgets = (loaded_pallet_weight - empty_pallet_weight) / WIDGET_WEIGHT;

    std::cout << "There are " << widgets << " widgets stacked on the pallet." << std::endl;

    return 0;
}