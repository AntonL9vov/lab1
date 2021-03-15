//
// Created by AntonLvov on 09.03.2021.
//
#include "functions.h"

void *sumFloat(void *n1, void *n2, void *res){
    *(float *)res = *(float *)n1 + *(float *)n2;
    return res;
}

void *multFloat(void *n1, void *n2, void *res){
    *(float *)res =*(float *)res + *(float *)n1 * *(float *)n2 ;
    return res;
}

void *scalarFloat(void *n1, float a, void *res){
    *(float *)res = *(float *)n1 * a;
    return res;
}

void *randFloat(void* res){
    float left, right;
    float fl = float_rand(-100, 100);
    memcpy(res, &fl, sizeof(float));
    return res;
}

void printFloat(void *num) {
    float *n = num;
    printf("%.2f  ", *n);
}
