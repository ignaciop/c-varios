#include "a6.h"

#include <cmath>
#include <array>
#include <iostream>

// The definitions need to be in the same namespace as the declarations
namespace johnny {
namespace mathlib {

// Global definition of PI
const float PI = 3.14f;

float distance(float a, float b) {
    return b - a;
}

int distance(int a, int b) {
    return b - a;
}

// The default argument can be specified only once, so here we don't repeat it
float distance(std::array<float, 3> a, std::array<float, 3> b) {
    // distance = square root of ( (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )
    // std::pow(x, 2) == x^2
    return std::sqrt(std::pow(b[0] - a[0], 2) + std::pow(b[1] - a[1], 2) + std::pow(b[2] - a[2], 2));
}

float circumference(float radius) {
    // Use the global variable PI
    return 2 * PI * radius;
}

float total_walking_distance(const std::array<std::array<float, 3>, 10>& locations) {
    float distance_walked_so_far = 0;
    // We keep summing the distance between a locations and the previous one.
    // we start at 1 because the first location (at index 0) has no previous location to compute the distance from.
    for(int current_location = 1; current_location < 10; current_location++) {
        int previous_location = current_location - 1;
        // We use the overload for points
        float current_distance = distance(locations[previous_location], locations[current_location]);
        distance_walked_so_far += current_distance;
    }
    return distance_walked_so_far;
}

}
}

const float ENEMY_VIEW_RADIUS_METERS = 5;

int main() {
    std::array<float, 3> enemy1_location = {2, 2 ,0};
    std::array<float, 3> enemy2_location = {2, 4 ,0};

    float enemy_distance = johnny::mathlib::distance(enemy1_location, enemy2_location);
    float distance_from_center = johnny::mathlib::distance(enemy1_location);

    using johnny::mathlib::circumference;
    float view_circumference_for_enemy = circumference(ENEMY_VIEW_RADIUS_METERS);

    float total_distance = johnny::mathlib::total_walking_distance({
        enemy1_location,
        {2, 3, 0}, // y += 1
        {2, 3, 3}, // z += 3
        {5, 3, 3}, // x += 3
        {8, 3, 3}, // x += 3
        {8, 3, 2}, // z -= 1
        {2, 3, 2}, // x -= 6
        {2, 3, 1}, // z -= 1
        {2, 3, 0}, // z -= 1
        enemy2_location
    });

    std::cout << "The two enemies are " << enemy_distance << "m apart and can see for a circumference of "
              << view_circumference_for_enemy << "m. To go to from one to the other they need to walk "
              << total_distance << "m.";
}