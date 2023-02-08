#include <iostream>
#include <cstdlib>
#include <ctime>

void roundShift(int array[], int size);
void print(int array[], int size);

int main() {
    const int LL = 1;
    const int UL = 100;
    const int ARRAY_SIZE = 10;

    int elements[ARRAY_SIZE] = {};

    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        elements[i] = LL + (rand() % (UL - LL + 1));
    }

    std::cout << "Original array: ";
    print(elements, ARRAY_SIZE);

    roundShift(elements, ARRAY_SIZE);

    std::cout << "Shifted array : ";
    print(elements, ARRAY_SIZE);

    return 0;
}

void roundShift(int array[], int size) {
    int first = array[0];

    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    array[size - 1] = first;
}

void print(int array[], int size) {    
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << '\n';
}