#include <iostream>
#include <cstdlib>
#include <ctime>

void print(int array[], int size);
void print2(int array[][6], int rows, int cols);
void diag_extract(int array[][6], int rows, int cols, int diag[], int antidiag[]);

int main() {
    const int LL = 100;
    const int UL = 199;
    const int COLS = 6;
    const int ROWS = 6;

    int elements[ROWS][COLS] = {};
    int diag[ROWS] = {};
    int antidiag[ROWS] = {};

    srand(time(0));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            elements[i][j] = LL + (rand() % (UL - LL + 1));
        }
    }

    print2(elements, ROWS, COLS);
    
    diag_extract(elements, ROWS, COLS, diag, antidiag);

    std::cout << "Diagonal elements from left to right: ";
    print(diag, ROWS);

    std::cout << "Diagonal elements from right to left: ";
    print(antidiag, ROWS);

    return 0;
}

void print(int array[], int size) {    
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << '\n';
}

void print2(int array[][6], int rows, int cols) {    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j] << " ";

            if (j == cols - 1) {
                std::cout << '\n';
            }
        }
    }
    
    std::cout << '\n';
}

void diag_extract(int array[][6], int rows, int cols, int diag[], int antidiag[]) {
    int index_diag = 0;
    int index_antidiag = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == i) {
                diag[index_diag++] = array[i][j];
            }

            if (j == cols - i - 1) {
                antidiag[index_antidiag++] = array[i][j];
            }
        }
    }
}