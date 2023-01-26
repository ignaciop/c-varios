#include <iostream>
#include <fstream>

int main() {
    std::ifstream rainfall_file;
    rainfall_file.open("data/rainfall.txt");

    std::string initial_month = "";
    std::string final_month = "";
    double value = 0.0;
    double total = 0.0;
    double avg = 0.0;
    int items = 0;

    if (rainfall_file) {
        rainfall_file >> initial_month;
        rainfall_file >> final_month;
    
        while (rainfall_file >> value) {
            total += value;

            items++;
        }
        
        rainfall_file.close();
    } else {
        std::cout << "Error opening the file." << std::endl;
    }

    avg = total / items;

    std::cout << "During the months of " << initial_month << " through " 
                << final_month << " the total rainfall was " << total 
                    << " and the average monthly rainfall was " << avg << std::endl;

    return 0;
}