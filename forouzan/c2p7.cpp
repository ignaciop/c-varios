#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your first name: " << std::endl;
    std::string first_name = "";
    getline(std::cin, first_name);

    std::cout << "Enter your last name: " << std::endl;
    std::string last_name = "";
    getline(std::cin, last_name);

    std::cout << "Your full name is: " << last_name << ", " << first_name << std::endl;

    return 0;
}