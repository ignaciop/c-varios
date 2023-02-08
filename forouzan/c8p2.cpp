#include <iostream>
#include <cstdlib>
#include <ctime>

void print(int array[], int size);
void minAndMax(int array[], int size, int& rMin, int& rMax);

int main() {
    const int LL = 1;
    const int UL = 100;
    const int ARRAY_SIZE = 10;

    int elements[ARRAY_SIZE] = {};

    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        elements[i] = LL + (rand() % (UL - LL + 1));

    }

    int min = elements[0];
    int max = min;

    minAndMax(elements, ARRAY_SIZE, min, max);
    print(elements, ARRAY_SIZE);

    std::cout << "Smallest element: " << min << std::endl;
    std::cout << "Largest element: " << max << std::endl;

    return 0;
}

void minAndMax(int array[], int size, int& rMin, int& rMax) {
    for (int i = 0; i < size; i++) {
        if (array[i] > rMax) {
            rMax = array[i];
        }

        if (array[i] < rMin) {
            rMin = array[i];
        }
    }
}

void print(int array[], int size) {    
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << '\n';
}