#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "systemConvert.h"

#define MAX 255

#define DECIMAL 10

void mainMenu();

int** loadMatrix(char[MAX]);
static void freeMatrix(int **array, size_t size);

#endif //MAIN_MENU_H