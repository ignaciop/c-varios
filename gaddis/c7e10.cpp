#include <iostream>
#include <string>
#include "classes/TeamScore.h"

int main() {
    std::cout << "Enter your team's name: ";
    std::string name = "";
    getline(std::cin, name);

    TeamScore ts1(name);

    int choice = 0;

    while (true) {
        std::cout << "\nSelect an option: " << std::endl;
        std::cout << "\t 1. Update Wins." << std::endl;
        std::cout << "\t 2. Update Ties." << std::endl;
        std::cout << "\t 3. Update Losses." << std::endl;
        std::cout << "\t 4. Display team's data." << std::endl;
        std::cout << "\t 5. Quit." << std::endl;
        std::cout << "Option? ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                ts1.updateWins();

                std::cout << "A win was added." << std::endl;

                break;
            case 2:
                ts1.updateTies();

                std::cout << "A tie was added." << std::endl;

                break;
            case 3:
                ts1.updateLosses();

                std::cout << "A loss was added." << std::endl;

                break;
            case 4:
                ts1.displayRecord();

                break;
            case 5:
                return 0;
            default:
                std::cout << "Please enter a valid option (1 to 5)." << std::endl;

                break;
        }
    }

    return 0;
}

