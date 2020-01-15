#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

#define DECIMAL 10

void addMatrixs();
void multiplicationMatrix();
int** loadMatrix(char[MAX], int*, int*);
static void freeMatrix(int **array, size_t size);

#endif //MATRIX_H