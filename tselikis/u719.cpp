#include <iostream>
#include <string>

int main() {
    const int WINGS = 10;
    const int ROOMS = 50;
    std::string hotel[WINGS][ROOMS] = {};
    int choice = 0;
    static bool hotel_full = false;

    // Initialize hotel with all rooms available.
    for (int i = 0; i < WINGS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            hotel[i][j] = "Available";
        }
    }
    
    while (true) {
        MENU:
        std:: cout << "Welcome to the CPP Hotel! It has " << WINGS << " wings and "
                << "in each one of them " << ROOMS << " rooms.\n" << std::endl;
        std::cout << "--------------------------------------\n";
        std::cout << "|                MENU                |\n";
        std::cout << "--------------------------------------\n";

        std::cout << "\nPlease select an option:\n" << std::endl;

        std::cout << "1. Display rooms in each wing." << std::endl;
        std::cout << "2. Make a reservation." << std::endl;
        std::cout << "3. Cancel a reservation." << std::endl;
        std::cout << "4. Exit.\n" << std::endl;
        
        std::cout << "Option: ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1) {
            std::cout << "--------------------------------------\n";
            std::cout << "|            HOTEL OVERVIEW          |\n";
            std::cout << "--------------------------------------\n";
            std::cout << "These are the rooms in each wing:\n" << std::endl;

            for (int i = 1; i <= WINGS; i++) {
                std::cout << "Wing " << i;

                int count_available = 0;

                for (int j = 1; j <= ROOMS; j++) {
                    std::cout << "\n      ⤷ Room " << j << ": " << hotel[i - 1][j - 1];

                    if (hotel[i - 1][j - 1] == "Available") {
                        count_available++;
                    }    
                }

                std::cout << "\n" << std::endl;
                std::cout << count_available << " rooms available, "
                            << ROOMS - count_available << " reserved." << std::endl;
                std::cout << std::endl;
                std::cout << "--------------------------------------\n";
            }
        }

        if (choice == 2) {
            std::cout << "--------------------------------------\n";
            std::cout << "|           ROOM RESERVATION         |\n";
            std::cout << "--------------------------------------\n";

            int wing_number = WINGS;
            bool wing_reserved = false;

            // First check if the hotel is full

            for (int i = 0; i < WINGS; i++) {
                for (int j = 0; j < ROOMS; j++) {
                    if (hotel[i][j] != "Reserved") {
                        hotel_full = false;
                        continue;
                    } else {
                        hotel_full = true;
                    }
                }

                if (!hotel_full) {
                    break;
                }
            }

            if (hotel_full) {
                    std::cout << "Sorry, the hotel is full." << std::endl;
                    goto MENU;
            }

            //Make reservation

            RESERVE:
            do {
                std::cout << "Please enter a wing number: ";
                std::cin >> wing_number;
            } while (wing_number <= 0 || wing_number > WINGS);


            for (int j = 0; j < ROOMS; j++) {

                if (hotel[wing_number - 1][j] == "Reserved") {
                    wing_reserved = true;

                } else {
                    hotel[wing_number - 1][j] = "Reserved";
                    std::cout << "\nCongratulations! You have reserved room "
                                << j + 1 << " on wing " << wing_number << "\n" <<  std::endl;
                    
                    wing_reserved = false;

                    break;
                }
            }

            if (wing_reserved) {
                std::cout << "Sorry, wing " << wing_number << " is full." << std::endl;
            
                goto RESERVE;
            }
        }

        if (choice == 3) {
            std::cout << "--------------------------------------\n";
            std::cout << "|         CANCEL RESERVATION         |\n";
            std::cout << "--------------------------------------\n";

            int wing_number = WINGS;
            int room_number = ROOMS;

            do {
                std::cout << "Please enter a wing number: ";
                std::cin >> wing_number;
            } while (wing_number <= 0 || wing_number > WINGS);

            do {
                std::cout << "Please enter a room number: ";
                std::cin >> room_number;
            } while (room_number <= 0 || room_number > ROOMS);

            if (hotel[wing_number - 1][room_number - 1] == "Reserved") {
                hotel[wing_number - 1][room_number - 1] = "Available";

                hotel_full = false;

                std::cout << "\nYour reservation has been canceled.\n" << std::endl;
            } else {
                std::cout << "\nSorry, the room is already available.\n" << std::endl;
            }

            goto MENU;
        }

        if (choice == 4) {
            break;
        }
    }

    std::cout << "--------------------------------------\n";
    std::cout << "|   THANK YOU FOR YOUR VISIT, BYE!   |\n";
    std::cout << "--------------------------------------\n";

    return 0;
}