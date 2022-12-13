#ifndef A6_H
#define A6_H

#include <array>
#include <cmath>

int distance(int i1, int i2);
float distance(float f1, float f2);
float distance(std::array<float, 3>& p1, std::array<float, 3>& p2 = {0, 0, 0});
float circumference(float radius);
float totalDistance(std::array<std::array<float, 3>, 5>& ps);

#endif