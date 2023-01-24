#include <iostream>

int main() {
    double user_temp;

    std::cout << "Enter temperature: "; 
    std::cin >> user_temp;

    std::cout << "\nAt " << user_temp << " F these substances will either "
                << " freeze or boil.\n";
    
    if (user_temp <= 32) {
        std::cout << "\nFreeze:\n";
        std::cout << "--------" << std::endl;
        std::cout << "Water" << std::endl;

        if (user_temp <= -38) {
            std::cout << "Mercury" << std::endl;

            if (user_temp <= -173) {
                std::cout << "Ethyl alcohol" << std::endl;

                if (user_temp <= -362) {
                    std::cout << "Oxygen" << std::endl;
                }
            }
        }
        std::cout << std::endl;
    }

    if (user_temp >= -306) {
        std::cout << "Boil: \n";
        std::cout << "--------" << std::endl;
        std::cout << "Oxygen." << std::endl;

        if (user_temp >= 172) {
            std::cout << "Ethyl alcohol." << std::endl;

            if (user_temp >= 212) {
                std::cout << "Water" << std::endl;

                if (user_temp >= 676) {
                    std::cout << "Mercury" << std::endl;
                }
            }
        }
        std::cout << std::endl;
    }

    return 0;
}