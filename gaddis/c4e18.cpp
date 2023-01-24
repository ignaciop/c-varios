#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Select medium: " << std::endl;
    std::cout << "\t1. Air" << std::endl;
    std::cout << "\t2. Water" << std::endl;
    std::cout << "\t3. Steel" << std::endl;
    std::cout << "Choice? ";

    int choice = 0;
    std::cin >> choice;

    std::cout << "Enter the number of feet the sound wave will travel: ";
    double x = 0.0;
    std::cin >> x;

    double c = 0.0;

    switch (choice) {
        case 1:
            c = 1100;
            break;
        case 2:
            c = 4900;
            break;
        case 3:
            c = 16400;
            break;
        default:
            break;
    }

    double t = x / c;

    std::cout << "It will take " << std::fixed << std::setprecision(4)
                << t << " seconds to the sound wave to travel "
                    << std::setprecision(2) << x << " feet at v = " 
                        << c << " f/s" << std::endl;
    
    return 0;
}