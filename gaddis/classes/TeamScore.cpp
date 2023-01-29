#include "TeamScore.h"
#include <iostream>

void TeamScore::displayRecord() {
    const int WIN_POINTS = 3;
    const int TIE_POINTS = 1;

    int wins_points = wins * WIN_POINTS;
    int ties_points = ties * TIE_POINTS;
    int total_points = wins_points + ties_points;

    std::cout << "\nTeam: " << teamName << std::endl;
    std::cout << "W: " << wins << ", T: " << ties << ", L: " << losses << std::endl;
    std::cout << "Total points: " << total_points << std::endl;
}