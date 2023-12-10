#include <stdio.h>

#define MAXDATA 1024

typedef struct {
    double data[MAXDATA];
    int nrows;
    int ncols;
} Matrix;

void printmat(Matrix M);
Matrix matrixmult(Matrix A, Matrix B);

int main(void) {
    Matrix A = { {1.2, 2.3,
                3.4, 4.5,
                5.6, 6.7},
               3,
               2};
    Matrix B = { {5.5, 6.6, 7.7,
                1.2, 2.1, 3.3},
               2,
               3};
               
    printmat(A);
    printmat(B);

    Matrix C = matrixmult(A, B);
    printmat(C);

    return 0;
}

// your code goes below...

void printmat(Matrix M) {
    printf("%s\n", "[");
    
    for (int i = 0; i < M.nrows; i++) {
        printf("%s", " ");
        
        for (int j = 0; j < M.ncols; j++) {
            printf("%f ", M.data[i + j]);
        }
        
        printf("%s\n", "\b");
    }
    
    printf("%s\n\n", "]");
}

Matrix matrixmult(Matrix A, Matrix B) {
    Matrix C = {.data = {0}, .nrows = A.nrows, .ncols = B.ncols};
    
    if (A.ncols != B.nrows) {
        printf("error: ncols of A does not equal nrows of B\n");
    } else {
        double count = 0.0;
        
        for (int i = 0; i < C.nrows; i++) {
            for (int j = 0; j < C.ncols; j++) {
                count = 0.0;

                for (int k = 0; k < C.ncols; k++) {
                    count += A.data[i * A.ncols + k] * B.data[k * B.ncols + j];
                }
            
                C.data[i * A.nrows + j] = count;
            }
        }
    }

    return C;
}