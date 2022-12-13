#include <iostream>

int main() {
    float goal[5];
    goal[0] = 0.9;
    goal[1] = 0.75;
    goal[2] = 0.5;
    goal[3] = 0.25;
    goal[4] = 0.10;

    float weight, target;

    std::cout << "Enter current weight: ";
    std::cin >> weight;
    
    std::cout << "\nEnter goal weight: ";
    std::cin >> target;

    std::cout << std::endl;

    size_t index = 0;

    for (float g : goal) {
        float loss = (weight - target) * g;
        
        std::cout << "Goal " << index << ": ";
        std::cout << target + loss << std::endl;
        ++index;
    }

    return 0;
}