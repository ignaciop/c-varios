#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    const int UNIT = 1000;

    std::ifstream people_file;
    people_file.open("data/people.txt");

    int value = 0;
    int year = 1910;

    if (people_file) {
        std::cout << "PRAIRIEVILLE POPULATION GROWTH" << std::endl;
        std::cout << "(each * represents 1000 people)" << std::endl;

        while (people_file >> value) {
            int star_count = value / UNIT;
            
            std::cout << std::right << year << std::setw(5);

            for (int i = 1; i <= star_count; i++) {
                std::cout << '*';
            }

            year += 20;
            
            std::cout << '\n';
        }
        
        people_file.close();
    } else {
        std::cout << "Error opening the file." << std::endl;
    }

    return 0;
}