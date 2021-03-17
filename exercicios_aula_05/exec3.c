#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    float* M;
    int dimension;
} typedef Matrix;

void inicialization(Matrix* matrix, int dimension){
    matrix->dimension = dimension;
    matrix->M = (float*)calloc(dimension*dimension, sizeof(float));
}

int indexMatrix(Matrix* matrix, int i, int j){ 
    return matrix->dimension * i + j;
}

void fillMatrix(Matrix* matrix){
    int index;
    for (int i = 0; i < matrix->dimension; i++)
    {
        for (int j = 0; j < matrix->dimension; j++)
        {
            if(i < j) continue;
            index = indexMatrix(matrix, i, j);
            *(matrix->M+index) = rand()%30;
        }        
    }    
}

void attribution(Matrix* matrix, int i, int j){

}

void showMatrix(Matrix* matrix){
    int index;
    for (int i = 0; i < matrix->dimension; i++)
    {
        printf("\n");
        for (int j = 0; j < matrix->dimension; j++)
        {
            index = indexMatrix(matrix, i, j);
            printf("%.2f\t", *(matrix->M+index));
        }
    }
}

int main(void)
{
    Matrix matrix;
    inicialization(&matrix, 20);
    fillMatrix(&matrix);
    showMatrix(&matrix);
    return 0;
}