#include <iostream>
#include <cstdlib>
#include <ctime>

void print(int array[], int size);
void oddsAndEvens(int array[], int size, int array2[], int array3[], int& oddIndex, int& evenIndex);

int main() {
    const int LL = 1;
    const int UL = 100;
    const int ARRAY_SIZE = 20;

    int elements[ARRAY_SIZE] = {};
    int odds[ARRAY_SIZE / 2] = {};
    int evens[ARRAY_SIZE / 2] = {};

    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        elements[i] = LL + (rand() % (UL - LL + 1));

    }

    int oddIndex = 0;
    int evenIndex = 0;

    std::cout << "Original array: ";
    print(elements, ARRAY_SIZE);

    oddsAndEvens(elements, ARRAY_SIZE, odds, evens, oddIndex, evenIndex);

    std::cout << "Odds array : ";
    print(odds, oddIndex);

    std::cout << "Evens array : ";
    print(evens, evenIndex);

    return 0;
}

void oddsAndEvens(int array[], int size, int array2[], int array3[], int& oddIndex, int& evenIndex) {
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 != 0) {
            array2[oddIndex++] = array[i];
        } else {
            array3[evenIndex++] = array[i];
        }
    }
}

void print(int array[], int size) {    
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << '\n';
}