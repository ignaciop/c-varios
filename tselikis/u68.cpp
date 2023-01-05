#include <iostream>

int main() {
    std::cout << "Enter initial height: ";
    float initial_height = 0.0;
    std::cin >> initial_height;

    std::cout << "Enter decrease ratio (in percentage): ";
    float decrease_ratio = 0.0;
    std::cin >> decrease_ratio;

    float final_height = initial_height / 4;
    float temp_height = initial_height;
    int bounces = 0;

    while (temp_height > final_height) {
        temp_height -= temp_height * (decrease_ratio / 100);
        
        std::cout << temp_height << " m." << std::endl;

        bounces++;
    }
        
    std::cout << "Takes " << bounces << " bounces to go from " 
                << initial_height << " m. to less than " << final_height << " m." << std::endl;

    return 0;
}