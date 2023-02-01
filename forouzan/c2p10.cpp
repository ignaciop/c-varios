#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your street number: " << std::endl;
    std::string street_number;
    getline(std::cin, street_number);

    std::cout << "Enter your street name: " << std::endl;
    std::string street_name;
    getline(std::cin, street_name);

    std::cout << "Enter your city name: " << std::endl;
    std::string city_name;
    getline(std::cin, city_name);

    std::cout << "Enter your state name: " << std::endl;
    std::string state_name;
    getline(std::cin, state_name);

    std::cout << "Enter your zip code: " << std::endl;
    std::string zip_code;
    getline(std::cin, zip_code);
    
    std::cout << street_number << " " << street_name << ", " << city_name << ", " << state_name
                << " " << zip_code << std::endl;

    return 0;
}