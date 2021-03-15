//
// Created by AntonLvov on 12.03.2021.
//

#include "complex.h"

complex *newComplex(const float realPart, const float complexPart) {
    complex *res = (complex*) malloc(sizeof(complex));
    res->realPart = realPart;
    res->complexPart = complexPart;
    res->size = sizeof(complex);
    return res;
}

void* complexAdd(void *num1, void *num2, void *res) {
    complex *n1 = num1;
    complex *n2 = num2;
    complex *n3 = newComplex(n1->realPart + n2->realPart, n1->complexPart + n2->complexPart);
    memcpy(res, n3, sizeof(complex));
    free(n3);
    return res;
}


void* complexMult(void *num1, void *num2, void *res) {
    complex *n1 = num1;
    complex *n2 = num2;
    complex *r = res;
    complex *n3 = newComplex(n1->realPart * n2->realPart - n1->complexPart * n2->complexPart + r->realPart,
                             n1->realPart * n2->complexPart + n1->complexPart * n2->realPart + r->complexPart);
    memcpy(res, n3, sizeof(complex));

    free(n3);
    return res;
}
void *complexScalar(void *num1, float a, void *res){
    complex *n1 = num1;
    complex *n2 = newComplex(n1->realPart*a, n1->complexPart*a);
    memcpy(res, n2, sizeof(complex));
    free(n2);
    return num1;
}
void* complexRand(void *res){
    float flr = float_rand(-100, 100);
    float flc = float_rand(-100, 100);
    complex *complex = newComplex(flr, flc);
    memcpy(res, complex, sizeof(float));
    free(complex);
    return res;
}

void complexPrint(void *num) {
    complex *n = num;

    printf("%0.2f", n->realPart);
    if(n->complexPart>=0){
        printf("+%0.2fi", n->complexPart);
    }else printf("%0.2fi", n->complexPart);

    printf("  ");
}

void getComplex(void *res) {
    printf("Input real part: ");
    float a = getFloatNumber(NULL, 0, 0);
    printf("Input complex part: ");
    float b = getFloatNumber(NULL, 0, 0);
    complex *r = newComplex(a, b);
    memcpy(res, r, sizeof(complex));
}
