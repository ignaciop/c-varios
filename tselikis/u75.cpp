#include <iostream>

int main() {
    const int ARR_SIZE = 100;
    int values[ARR_SIZE] = {};
    int value = 0;
    int last = 0;
    int greater_than_last = 0;
    int greater_than_avg = 0;
    int sum = 0;

    for (int i = 0; i < ARR_SIZE; i++) {
        if (i == 0) {
            std::cout << "Enter the integer value of last element: ";
            std::cin >> last;

            values[ARR_SIZE - 1] = last;
            sum += last;
        }

        if (i != ARR_SIZE - 1) {
            std::cout << "Enter an integer value: ";
            std::cin >> value;

            values[i] = value;
            sum += values[i];
        }

        if (values[i] > last) {
            greater_than_last++;
        }
    }

    float avg = (static_cast<float>(sum)) / ARR_SIZE;

    for (int i = 0; i < ARR_SIZE; i++) {
        if (values[i] > avg) {
            greater_than_avg++;
        }
    }

    std::cout << "There are " << greater_than_last 
                << " elements greater than " << last << std::endl;

    std::cout << "There are " << greater_than_avg 
                << " elements greater than " << avg << std::endl;
 
    return 0;
}