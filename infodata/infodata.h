#ifndef INFOBASE
#define INFOBASE

#include <stdio.h>
#include <stdlib.h>

#define NOTNULL(X) X!=NULL

void sSinglePointerIData(int* data);
void sDoublePointerIData(int** data, int rows, int cols);
void sDoublePointerCData(char** data, int rows, int cols);

#endif