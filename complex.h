//
// Created by AntonLvov on 12.03.2021.
//

#ifndef LAB_NUMBER_1_COMPLEX_H
#define LAB_NUMBER_1_COMPLEX_H
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "math.h"

typedef struct complex {
    float realPart;
    float complexPart;

    size_t size;
} complex;

complex *newComplex(float realPart, float complexPart);

void* complexAdd(void *num1, void*num2, void *res);
void* complexMult(void *num1, void *num2, void *res);
void* complexScalar(void *num1, float a, void *res);
void* complexRand(void *res);

void complexPrint(void *num);
void getComplex(void *res);
void getComplexRandom(void *res);
#endif //UNTITLED4_COMPLEX_H
