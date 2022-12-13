#include <iostream>
#include "a6.h"

const float PI = 3.1415;

int distance(int i1, int i2) {
    return std::sqrt(std::pow(i1, 2) + std::pow(i2, 2));
}

float distance(float f1, float f2) {
    return std::sqrt(std::pow(f1, 2) + std::pow(f2, 2));
}

float distance(std::array<float, 3>& p1, std::array<float, 3>& p2 = {0, 0, 0}) {
    return std::sqrt(std::pow(p2[0] - p1[0],2) + std::pow(p2[1] - p1[1],2) + std::pow(p2[2] - p1[2],2));
}

float circumference(float radius) {
    return 2 * PI * radius;
}

float totalDistance(std::array<std::array<float, 3>, 5>& ps) {
    float d1 = distance(ps[0], ps[1]);
    float d2 = distance(ps[1], ps[2]);
    float d3 = distance(ps[2], ps[3]);
    float d4 = distance(ps[3], ps[4]);

    return d1 + d2 + d3 + d4;
}

int main() {
    std::array<std::array<float, 3>, 5> ps = {{0,0,0}, {1,0,0}, {1,1,0},
{0,1,0}, {0,1,1}};

    std::cout << "Total distance: " << totalDistance(ps) << std::endl;
    
    return 0;
}