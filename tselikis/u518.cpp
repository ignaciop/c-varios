#include <iostream>

int main() {
    std::cout << "Enter type of vehicle (1. Moto, 2. Auto): ";
    int vehicle = 0;
    std::cin >> vehicle;

    std::cout << "Enter cybism: ";
    int cybism = 0;
    std::cin >> cybism;

    std::cout << "Enter days to rent the vehicle: ";
    int rent = 0;
    std::cin >> rent;

    std::cout << "Do you want insurance (1. Yes, 2. No)?: ";
    int insurance = 0;
    std::cin >> insurance;

    float total_cost = 0.0;

    switch (vehicle) {
    case 1:
        switch (rent) {
        case 1:
        case 2:
            if (cybism <= 100) {
                total_cost = 30;
            } else {
                total_cost = 40;
            }
            break;
        case 3:
        case 4:
        case 5:
            if (cybism <= 100) {
                total_cost = 25;
            } else {
                total_cost = 35;
            }
            break;
        default:
            if (cybism <= 100) {
                total_cost = 20;
            } else {
                total_cost = 30;
            }
            break;
        }
        break;
    
    case 2:
        switch (rent) {
        case 1:
        case 2:
            if (cybism <= 1000) {
                total_cost = 60;
            } else {
                total_cost = 80;
            }
            break;
        case 3:
        case 4:
        case 5:
            if (cybism <= 1000) {
                total_cost = 55;
            } else {
                total_cost = 70;
            }
            break;
        default:
            if (cybism <= 1000) {
                total_cost = 50;
            } else {
                total_cost = 60;
            }
            break;
        }
        break;

    default:
        break;
    }

    if (insurance == 1) {
        total_cost += total_cost * 0.05;
    }

    std::cout << "Total cost: " << total_cost << std::endl;

    return 0;
}