//
// Created by AntonLvov on 09.03.2021.
//
#include "matrix.h"
#include "functions.h"
Matrix *createMatrix(int length, int height, size_t element_size, const struct functions *f){
    Matrix *m = (Matrix *) calloc(1, sizeof(Matrix));
    m->functions = f;
    m->length = length;
    m->height = height;
    m->element_size = element_size;
    m->matrix = calloc(length*height, element_size);
    return m;
}

void printMatrix(Matrix *m){
    for (int i = 0; i < m->height; ++i) {
        for (int j = 0; j < m->length; ++j) {
            m->functions->print((void *)(m->matrix+((i*m->length)+j)*m->element_size));
        }
        printf("\n");
    }
}

void fillMatrix(Matrix *m, int toPrint){
    printf("Input numbers to the matrix %d * %d\n", m->height, m->length );
    for (int i = 0; i < m->height; ++i) {
        for (int j = 0; j <  m->length; ++j){
            void *point = (void *)((m->matrix)+((i*m->length)+j)*m->element_size);
            m->functions->getNumber(point);
        }
    }
    if(toPrint) printMatrix(m);
}

void fillMatrixRand(Matrix *m, int toPrint){
    for (int i = 0; i < m->height; ++i) {
        for (int j = 0; j <  m->length; ++j){
            void *point = (void *)(m->matrix+((i*m->length)+j)*m->element_size);
            m->functions->fillRand(point);
        }
    }
    if(toPrint) printMatrix(m);
}

Matrix *multipleMatrix(Matrix *mat1, Matrix *mat2){
    Matrix *mult = createMatrix(mat2->length, mat1->height, mat1->element_size, mat1->functions);
    void *m1, *m2, *res;
    for (int i = 0; i < mat1->length; ++i) {
        for (int j = 0; j < mat2->height; ++j){
            for (int k = 0; k < mat1->height; ++k) {
                m1 = (void *)(mat1->matrix+((i*mat1->length)+k)*mat1->element_size);
                m2 = (void *)(mat2->matrix+((k*mat2->length)+j)*mat2->element_size);
                res = (void *)(mult->matrix+((i*mult->length)+j)*mult->element_size);
                mat1->functions->mult(m1, m2, res);
            }
        }
    }
    return mult;
}

Matrix *sumMatrix(Matrix *mat1, Matrix *mat2){
    Matrix *sum = createMatrix(mat1->length, mat1->height, mat1->element_size, mat1->functions);
    void *m1, *m2, *res;
    for (int i = 0; i < mat1->length; ++i) {
        for (int j = 0; j < mat1->height; ++j){
            m1 = (void *)(mat1->matrix+((i*mat1->length)+j)*mat1->element_size);
            m2 = (void *)(mat2->matrix+((i*mat2->length)+j)*mat2->element_size);
            res = (void *)(sum->matrix+((i*sum->length)+j)*sum->element_size);
            mat1->functions->sum(m1, m2, res);
        }
    }
    return sum;
}

Matrix *scalarMatrix(Matrix *mat1, float a){
    Matrix *scalar = createMatrix(mat1->length, mat1->height, mat1->element_size, mat1->functions);
    void *m1, *res;
    for (int i = 0; i < mat1->length; ++i) {
        for (int j = 0; j < mat1->height; ++j){
            m1 = (void *)(mat1->matrix+((i*mat1->length)+j)*mat1->element_size);
            res = (void *)(scalar->matrix+((i*scalar->length)+j)*scalar->element_size);
            mat1->functions->scalar(m1, a, res);
        }
    }
    return scalar;
}

void deleteMatrix(Matrix *m){
    for (int i = 1; i < m->height; ++i) {
        for (int j = 0; j < m->length; ++j) free((m->matrix+((i*m->length)+j)*m->element_size));
    }
    free(m);
}

