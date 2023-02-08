#include <iostream>
#include <cstdlib>
#include <ctime>

void print(int array[], int size);
void reverse(int array[], int size, int array2[]);

int main() {
    const int LL = 1;
    const int UL = 100;
    const int ARRAY_SIZE = 10;

    int elements[ARRAY_SIZE] = {};
    int elements2[ARRAY_SIZE] = {};

    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        elements[i] = LL + (rand() % (UL - LL + 1));

    }

    std::cout << "Original array: ";
    print(elements, ARRAY_SIZE);

    reverse(elements, ARRAY_SIZE, elements2);

    std::cout << "Reverse array : ";
    print(elements2, ARRAY_SIZE);

    return 0;
}

void reverse(int array[], int size, int array2[]) {
    for (int i = 0; i < size; i++) {
        array2[i] = array[size - 1 - i];
    }
}

void print(int array[], int size) {    
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << '\n';
}