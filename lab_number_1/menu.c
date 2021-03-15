//
// Created by AntonLvov on 14.03.2021.
//
#include "menu.h"
int getInt(int *n, int down, int up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err, num;

    do {
        err = scanf("%d", &num);
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

Matrix *createFloatMatrix(){
    functions *functionsFloat = malloc(sizeof(functions));
    functionsFloat->sum = sumFloat;
    functionsFloat->mult = multFloat;
    functionsFloat->scalar = scalarFloat;
    functionsFloat->fillRand = randFloat;
    functionsFloat->print = printFloat;
    functionsFloat->getNumber = getFloat;
    Matrix *matrix = createMatrixIn(sizeof(float), functionsFloat);
    return matrix;
}

Matrix *createComplexMatrix(){
    functions *functionsComplex = malloc(sizeof(functions));
    functionsComplex->sum = complexAdd;
    functionsComplex->mult = complexMult;
    functionsComplex->scalar = complexScalar;
    functionsComplex->fillRand = complexRand;
    functionsComplex->print = complexPrint;
    functionsComplex->getNumber = getComplex;
    Matrix *matrix = createMatrixIn(sizeof(complex), functionsComplex);
    return matrix;
}

Matrix *getMatrix(){
    int n;
    printf("Input number: \n"
           "  1) float matrix\n"
           "  2) complex matrix\n");
    getInt(&n, 1, 2);

    Matrix *matrix;
    switch (n) {
        case 1: matrix = createFloatMatrix(); break;
        case 2: matrix = createComplexMatrix(); break;
        default: matrix = NULL; break;
    }

    printf("How do you want to fill matrix: \n"
           "  1) random\n"
           "  2) by yourself\n");
    getInt(&n, 1, 2);
    switch (n) {
        case 1: fillMatrixRand(matrix, 1); break;
        case 2: fillMatrix(matrix, 1); break;
        default: matrix = NULL; break;
    }

    return matrix;
}

void printMenu(){
    Matrix *m1;
    Matrix *m2;
    printf("1: Multiply two matrices \n"
           "2: Sum two matrices\n"
           "3: Scalar multiply matrix\n"
           "Input number: ");
    int n;
    getInt(&n,1, 3 );
    switch (n) {
        case 1:
            printf("\nFirst matrix\n");
            m1 = getMatrix();
            printf("\nSecond matrix\n");
            m2 = getMatrix();
            if(m1->element_size!=m2->element_size){
                printf("Matrices types aren't equal\n");
                break;
            }
            if (ifMult(m1, m2)) break;
            printf("\n ...multiplying matrices...\n");
            Matrix *mult = multipleMatrix(m1, m2);
            printf("\nDone, multiplied matrix:\n");
            printMatrix(mult);
        break;
        case 2:
            printf("\nFirst matrix\n");
            m1 = getMatrix();
            printf("\nSecond matrix\n");
            m2 = getMatrix();
            if(m1->element_size!=m2->element_size){
                printf("Matrices types aren't equal\n");
                break;
            }
            if (ifSum(m1, m2)) break;
            printf("\n ...summing matrices...\n");
            Matrix *sum = sumMatrix(m1, m2);
            printf("\nDone, summed matrix:\n");
            printMatrix(sum);
            break;
        case 3:
            m1 = getMatrix();
            Matrix *scalar = scalarMatrix(m1);
            printMatrix(scalar);
            break;
        default:  break;
    }
}

