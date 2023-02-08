#include <iostream>
#include <cstdlib>
#include <ctime>

void print(int array[], int size);

int main() {
    const int LL = 100;
    const int UL = 200;
    const int ARRAY_SIZE = 100;

    int elements[ARRAY_SIZE] = {};

    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        elements[i] = LL + (rand() % (UL - LL + 1));

    }

    print(elements, ARRAY_SIZE);

    return 0;
}

void print(int array[], int size) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
        count++;

        if (count == 10) {
            std::cout << '\n';
            count = 0;
        }
    }
}