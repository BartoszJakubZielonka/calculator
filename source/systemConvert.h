#ifndef SYSTEM_CONVERT_H
#define SYSTEM_CONVERT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

#define BINARY 2
#define OCTAL 8
#define HEXADECIMAL 16
#define DECIMAL 10

void systemConvert();

double anyToDecimal(char*, int);
void decimalToAny(double, int, int);

int getIntegralValue(char);
char getCharValue(int);

#endif //SYSTEM_CONVERT_H