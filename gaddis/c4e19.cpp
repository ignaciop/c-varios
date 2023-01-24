#include <iostream>

int main() {
    std::cout << "Select medium: " << std::endl;
    std::cout << "\t1. Carbon dioxide" << std::endl;
    std::cout << "\t2. Air" << std::endl;
    std::cout << "\t3. Helium" << std::endl;
    std::cout << "\t4. Hydrogen" << std::endl;

    std::cout << "Choice? ";

    int choice = 1;
    std::cin >> choice;

    if (choice <= 0 || choice >= 5) {
        std::cout << "Please re-run the program with a valid choice" << std::endl;

        return 0;
    }

    std::cout << "Enter the number of seconds: ";
    double t = 0.0;
    std::cin >> t;

    double c = 0.0;

    switch (choice) {
        case 1:
            c = 258.0;
            break;
        case 2:
            c = 331.5;
            break;
        case 3:
            c = 972.0;
            break;
        case 4:
            c = 1270.0;
            break;
        default:
            break;
    }

    double x = c * t;

    std::cout << "The sound wave travelled " << x << " feet, taking " 
                << t << " seconds at v = " << c << " f/s" << std::endl;
    
    return 0;
}