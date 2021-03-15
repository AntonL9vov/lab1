//
// Created by AntonLvov on 09.03.2021.
//

#ifndef UNTITLED4_FUNCTIONS_H
#define UNTITLED4_FUNCTIONS_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

typedef struct functions{
    void (*sum)(void *n1, void *n2, void *res);
    void (*mult)(void *n1, void *n2, void *res);
    void (*scalar)(void *n1, float a, void *res);
    void (*fillRand)(void *res);
    void (*getNumber)(void *res);

    void (*print)(void *n1);
}functions;

void *sumFloat(void *n1, void *n2, void *res);
void *multFloat(void *n1, void *n2, void *res);
void *scalarFloat(void *n1, float a, void *res);
void *randFloat(void *res);

void printFloat(void *n1);
#endif //UNTITLED4_FUNCTIONS_H
