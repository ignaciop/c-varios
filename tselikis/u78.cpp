#include <iostream>

int main() {
    const int ARR_SIZE = 10;
    int values[ARR_SIZE] = {};


    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << "Enter integer value: ";
        std::cin >> values[i];
    }

    
 
    return 0;
}