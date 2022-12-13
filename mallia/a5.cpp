#include <iostream>

namespace LamborghiniCar {
    void output() {
        std::cout << "Congratulations! You deserve the Lamborghini." << std::endl;
    }
}

namespace PorscheCar {
    void output() {
        std::cout << "Congratulations! You deserve the Porsche." << std::endl;
    }
}


int main() {
    std::cout << "Please enter number 1 or 2: ";
    int magicNumber;
    std::cin >> magicNumber;
   
    if (magicNumber == 1) {
        LamborghiniCar::output();
    } else if (magicNumber == 2) {
        PorscheCar::output(); 
    } else {
        std::cout << "Please type the correct magic number." << std::endl;
    }

    return 0;
}