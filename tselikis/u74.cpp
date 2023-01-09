#include <iostream>
#include <vector>

int main() {
    std::vector<double> values = {};
    std::vector<double>::iterator iter;
    double value = 0.0;

    do {
        std::cout << "Enter value: ";
        std::cin >> value;

        if (value > 5.0) {
            values.push_back(value);
        }
    } while (value != -1);

    double min = values.at(0);

    for (iter = values.begin(); iter != values.end(); iter++) {
        if (*iter < min) {
            min = *iter;
        }
    }

    std::cout << "\nMinimum stored: " << min << std::endl;
    
    return 0;
}