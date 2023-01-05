#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL)); // Initial random seed

    std::cout << "Enter an integer: ";
    int number = 0;
    std::cin >> number;

    int previous_bit = 0;
    int pairs = 0;

    for (int i = 0; i < number; i++) {
        unsigned int bit = rand() % 2;
        std::cout << bit << " ";

        if (i == 0) {
            continue;
        }
       
        if (previous_bit == 0 && bit == 1) {
            pairs++;
        }
        
        previous_bit = bit;
    }

    std::cout << "\nNumber of succesive 01 pairs: " << pairs << std::endl;

    return 0;
}

//TODO: rough edge cases (most of the times counts 01 pairs isolated) and cannot figure out succesive 01's pairs