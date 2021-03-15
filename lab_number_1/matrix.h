//
// Created by AntonLvov on 09.03.2021.
//

#ifndef UNTITLED4_MATRIX_H
#define UNTITLED4_MATRIX_H
#include "functions.h"
#include "math.h"

typedef struct Matrix{
    void *matrix;

    int length, height;
    size_t element_size;

    struct functions* functions;
}Matrix;

Matrix *createMatrix(int length, int height, size_t element_size, const struct functions *f);
Matrix *createMatrixIn(size_t element_size, const struct functions *f);

void printMatrix();

void fillMatrix(Matrix *m, int toPrint);
void fillMatrixRand(Matrix *m, int toPrint);

int ifMult(Matrix *m1, Matrix *m2);
Matrix *multipleMatrix(Matrix *m1, Matrix *m2);

int ifSum(Matrix *m1, Matrix *m2);
Matrix *sumMatrix(Matrix *m1, Matrix *m2);

Matrix *scalarMatrix(Matrix *m1);

#endif //UNTITLED4_MATRIX_H
