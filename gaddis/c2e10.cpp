#include <iostream>
#include <string>

int main() {
    std::string name = "Lisa Simpson";
    std::string address = "742 Evergreen Terrace";
    std::string city = "Springfield";
    std::string state = "Oregon";
    std::string zip_code = "97124";
    std::string phone_number = "(939)-555-0113";
    std::string college_major = "Politics";

    std::cout << "Name: " << name << "\nYour address, with city, state and zip code: "
                << address << ", " << city << ", " << state << ", " << zip_code
                    << "\nYour telephone number: " << phone_number << "\nCollege major: "
                        << college_major << std::endl;

    return 0;
}