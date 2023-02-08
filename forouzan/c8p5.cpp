#include <iostream>
#include <cstdlib>
#include <ctime>

void print(int array[], int size);
void minAndMax(int array[], int size, int& rMin, int& rMax);
void array_ext(int array[], int size, int array2[]);

int main() {
    const int LL = 1;
    const int UL = 100;
    const int ARRAY_SIZE = 10;

    int elements[ARRAY_SIZE] = {};
    int elements2[ARRAY_SIZE - 2] = {};

    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        elements[i] = LL + (rand() % (UL - LL + 1));

    }

    std::cout << "Original array: ";
    print(elements, ARRAY_SIZE);

    array_ext(elements, ARRAY_SIZE, elements2);

    std::cout << "Array without min and max values : ";
    print(elements2, ARRAY_SIZE - 2);

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

void array_ext(int array[], int size, int array2[]) {
    int min = array[0];
    int max = min;
    int index = 0;

    minAndMax(array, size, min, max);

    for (int i = 0; i < size; i++) {
        if (array[i] != min && array[i] != max) {
            array2[index++] = array[i];
        }
    }
}

void print(int array[], int size) {    
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << '\n';
}