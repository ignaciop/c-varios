#include <iostream>

int main() {
    const int ARR_SIZE = 5;

    double grades[ARR_SIZE] = {};
    double frequencies[ARR_SIZE] = {};

    for (int i = 0; i < ARR_SIZE; i++) {
        do {
            std::cout << "Enter grade in the [0, 10] range: ";
            std::cin >> grades[i];
        } while (grades[i] < 0.0 || grades[i] > 10.0);
    }

    for (int i = 0; i < ARR_SIZE; i++) {
        int freq = 0;

        for (int j = 0; j < ARR_SIZE; j++) {
            if (grades[i] == grades[j]) {
                freq++;
            }
        }

        frequencies[i] = freq;
    }

    double max_freq = frequencies[0];
    double note = grades[0];

    for (int i = 0; i < ARR_SIZE; i++) {
         if (frequencies[i] > max_freq) {
            max_freq = frequencies[i];
            note = grades[i];
         }
    } 

    if (max_freq > 1) {
        std::cout << "\n" << note << " has appeared " << max_freq << " times.\n";
    }
    
    return 0;
}