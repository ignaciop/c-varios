#include <iostream>

int main() {
    double avg_temp_nyc = 85.0F + 85.0F * 0.02F;
    double avg_temp_denver = 88.0F + 88.0F * 0.02F;
    double avg_temp_phoenix = 106.0F + 106.0F * 0.02F;

    std::cout << "Average July high temperature in NYC: " << avg_temp_nyc << "ºF" << std::endl;
    std::cout << "Average July high temperature in Denver: " << avg_temp_denver << "ºF" << std::endl;
    std::cout << "Average July high temperature in Phoenix: " << avg_temp_phoenix << "ºF" << std::endl;

    return 0;
}