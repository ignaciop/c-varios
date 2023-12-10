#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *data;
    int nrows;
    int ncols;
} Matrix;

void printmat(Matrix *M);
void matrixmult(Matrix *A, Matrix *B, Matrix *C);
Matrix *createMatrix(int nrows, int ncols);
void destroyMatrix(Matrix *M);

int main(void) {
    Matrix *A = createMatrix(3, 2);
    A->data[0] = 1.2;
    A->data[1] = 2.3;
    A->data[2] = 3.4;
    A->data[3] = 4.5;
    A->data[4] = 5.6;
    A->data[5] = 6.7;
    printmat(A);

    Matrix *B = createMatrix(2, 3);
    B->data[0] = 5.5;
    B->data[1] = 6.6;
    B->data[2] = 7.7;
    B->data[3] = 1.2;
    B->data[4] = 2.1;
    B->data[5] = 3.3;
    printmat(B);

    Matrix *C = createMatrix(3, 3);
    matrixmult(A, B, C);
    printmat(C);

    destroyMatrix(A);
    destroyMatrix(B);
    destroyMatrix(C);
    
    return 0;
}

// your code goes below...

Matrix *createMatrix(int nrows, int ncols) {
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    
    if (m == NULL) {
        perror("Cannot allocate memory for Matrix");
        exit(EXIT_FAILURE);
    }
    
    m->data = (double *)malloc(sizeof(double) * nrows * ncols);
    
    if (m->data == NULL) {
        perror("Cannot allocate memory for data array inside Matrix");
        exit(EXIT_FAILURE);
    }
    
    m->nrows = nrows;
    m->ncols = ncols;
    
    return m;
}

void destroyMatrix(Matrix *M) {
    free(M->data);
    M->data = NULL;
    
    free(M);
    M = NULL;
}

void printmat(Matrix *M) {
    printf("%s\n", "[");
    
    for (int i = 0; i < M->nrows; i++) {
        printf("%s", " ");
        
        for (int j = 0; j < M->ncols; j++) {
            printf("%f ", M->data[i * M->ncols + j]);
        }
        
        printf("%s\n", "\b");
    }
    
    printf("%s\n\n", "]");
}

void matrixmult(Matrix *A, Matrix *B, Matrix *C) {
    for (int i = 0; i < C->nrows; i++) {
        for (int j = 0; j < C->ncols; j++) {
            double count = 0.0;

            for (int k = 0; k < C->ncols; k++) {
                count += A->data[i * A->ncols + k] * B->data[k * B->ncols + j];
            }
        
            C->data[i * C->ncols + j] = count;
        }
    }
}