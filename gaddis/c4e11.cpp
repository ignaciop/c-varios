#include <iostream>
#include <string>

int main() {
    std::cout << "Enter first color (red, blue or yellow): ";
    std::string color1 = "";
    getline(std::cin, color1);

    std::cout << "Enter second color (red, blue or yellow): ";
    std::string color2 = "";
    getline(std::cin, color2);

    if ((color1 == "red" || color1 == "blue" || color1 == "yellow") && (color2 == "red" || color2 == "blue" || color2 == "yellow")) {
        if ((color1 == "red" && color2 == "blue") || (color1 == "blue" && color2 == "red")) {
            std::cout << "Secondary color: purple" << std::endl;
        }

        if ((color1 == "red" && color2 == "yellow") || (color1 == "yellow" && color2 == "red")) {
            std::cout << "Secondary color: orange" << std::endl;
        }

        if ((color1 == "blue" && color2 == "yellow") || (color1 == "yellow" && color2 == "blue")) {
            std::cout << "Secondary color: green" << std::endl;
        }  
    } else {
        std::cout << "Please re-run the program and enter the specified colors." << std::endl;
    }
    
    return 0;
}