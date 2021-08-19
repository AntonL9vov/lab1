//
// Created by AntonLvov on 09.03.2021.
//

#ifndef LAB_NUMBER_1_MATRIX_H
#define LAB_NUMBER_1_MATRIX_H
#include "functions.h"
#include "math.h"

typedef struct Matrix{
    void *matrix;

    int length, height;
    size_t element_size;

    struct functions *functions;
}Matrix;

Matrix *createMatrix(int length, int height, size_t element_size, const struct functions *f);

void printMatrix();

void fillMatrix(Matrix *m, int toPrint);
void fillMatrixRand(Matrix *m, int toPrint);

Matrix *multipleMatrix(Matrix *m1, Matrix *m2);

Matrix *sumMatrix(Matrix *m1, Matrix *m2);

Matrix *scalarMatrix(Matrix *m1, float a);

void deleteMatrix(Matrix *m);
#endif //UNTITLED4_MATRIX_H
