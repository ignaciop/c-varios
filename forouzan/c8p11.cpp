#include <iostream>
#include <cstdlib>
#include <ctime>

void print(int array[], int size);
void print2(int array[][2], int rows, int cols);
void merge(int array[][2], int final_size, int array1[], int array2[]);

int main() {
    const int LL = 100;
    const int UL = 199;
    const int ARRAY_SIZE = 5;

    int elements[ARRAY_SIZE] = {};
    int elements2[ARRAY_SIZE] = {};
    int merged_array[ARRAY_SIZE][ARRAY_SIZE / 2] = {};

    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        elements[i] = LL + (rand() % (UL - LL + 1));
        elements2[i] = LL + (rand() % (UL - LL + 1));
    }

    std::cout << "Array 1     : ";
    print(elements, ARRAY_SIZE);

    std::cout << "Array 2     : ";
    print(elements2, ARRAY_SIZE);

    merge(merged_array, ARRAY_SIZE, elements, elements2);

    std::cout << "\n2D Merged array: " << std::endl;
    print2(merged_array, ARRAY_SIZE, ARRAY_SIZE / 2);

    return 0;
}

void print(int array[], int size) {    
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << '\n';
}

void print2(int array[][2], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j] << " ";

            if (j == cols - 1) {
                std::cout << '\n';
            }
        }
    }
}

void merge(int array[][2], int final_size, int array1[], int array2[]) {
    for (int j = 0; j < final_size; j++) {
        array[j][0] = array1[j];
        array[j][1] = array2[j];
    }
}