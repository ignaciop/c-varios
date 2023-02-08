#include <iostream>
#include <cstdlib>
#include <ctime>

void print(int array[], int size);
void merge(int array[], int final_size, int array1[], int array2[]);

int main() {
    const int LL = 100;
    const int UL = 199;
    const int ARRAY_SIZE = 5;

    int elements[ARRAY_SIZE] = {};
    int elements2[ARRAY_SIZE] = {};
    int merged_array[ARRAY_SIZE * 2] = {};

    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        elements[i] = LL + (rand() % (UL - LL + 1));
        elements2[i] = LL + (rand() % (UL - LL + 1));
    }

    std::cout << "Array 1     : ";
    print(elements, ARRAY_SIZE);

    std::cout << "Array 2     : ";
    print(elements2, ARRAY_SIZE);

    merge(merged_array, ARRAY_SIZE * 2, elements, elements2);

    std::cout << "Merged array: ";
    print(merged_array, ARRAY_SIZE * 2);

    return 0;
}

void print(int array[], int size) {    
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << '\n';
}

void merge(int array[], int final_size, int array1[], int array2[]) {
    for (int i = 0; i < final_size / 2; i++) {
        array[i] = array1[i];
    }

    for (int i = final_size / 2; i < final_size; i++) {
        array[i] = array2[i - final_size / 2];
    }
}