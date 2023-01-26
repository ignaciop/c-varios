#include <iostream>
#include <fstream>

int main() {
    std::ifstream lineup_file;
    lineup_file.open("data/lineUp.txt");

    int i = 1;

    std::string name = "";
    std::string max = "";
    std::string min = "";

    if (lineup_file) {
        while (lineup_file >> name) {
            if (i == 1) {
                max = min = name;
            }

            if (name > max) {
                max = name;
            }

            if (name < min) {
                min = name;
            }

            i++;
        }
        
        lineup_file.close();
    } else {
        std::cout << "Error opening the file." << std::endl;
    }

    std::cout << "Student at the front of the line: " << min << std::endl;
    std::cout << "Student at the back of the line: " << max << std::endl;

    return 0;
}