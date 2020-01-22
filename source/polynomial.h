#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdlib.h>
#include <stdio.h>

float horner(float[], int, float);

float* findZero(float[], float, float, float, int, int*);

void polynomial(char*, char*);

#endif //POLYNOMIAL_H
