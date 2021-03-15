//
// Created by AntonLvov on 15.03.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float float_rand( float min, float max ){
    float scale = rand() / (float) RAND_MAX;
    return min + scale * ( max - min );
}
void getFloat(void *res) {
    float num;
    printf("Input number: \n");
    scanf("%f", &num);
    memcpy(res, &num, sizeof(float));
}

float getFloatNumber(float *n, float down, float up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err;
    float num;

    do {
        err = scanf("%f", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Wrong, try again\n");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}
