#include <stdio.h>
#include <stdlib.h>

/* 
Criação
Atribuição
Consulta
*/

struct matrix {
    int d; /* representa as dimensoes */
    float** M; /* representa a matriz */
} typedef Matrix;


Matrix* createMatrix(int dimensions){
    Matrix* m;
    /* aloca memoria para ponteiro de matriz */
    m = (Matrix*)malloc(sizeof(Matrix)); 
    m->d = dimensions; 
    /* aloca memoria para 2 dimensoes de floats(representara a tabela) */
    m->M = (float**)malloc(sizeof(float*)*m->d); /* aloca memoria para */
    /* aloca dinamicamente a quantidade NxN(matriz quadrada) */
    for (int i = 0; i < m->d; i++)
        *(m->M+i) = (float*)calloc(m->d, sizeof(float));    
    /* retorna o ponteiro */
    return m;
}

void insertMatrix(Matrix* m, float v, int i, int j){
    /* insere na posicao m[i][j] */
    *(*(m->M+i)+j) = v;
}

float searchMatrix(Matrix* m, int i , int j){
    /* procura na matriz em uma posicao m[i][j] */
    if(i > (m->d-1) || j > (m->d-1)){
        printf("value outside array\n");
        return -1.0;
    } 
    /* retorna caso nao encontra */
    return *(*(m->M+i)+j);
}

void printMatrix(Matrix* m){
    int i, j;
    for (i = 0; i < m->d; i++){
        for (j = 0; j < m->d; j++)
            printf("%.2f\t", *(*(m->M+i)+j));
        printf("\n");
    }    
}

void destroyMatrix(Matrix* m){
    int i, j;
    /* limpa todos os ponteiros alocados dinamicamente */
    for (i = 0; i < m->d; i++)
        free(m->M+i);
    free(m->M);
    free(m);    
}

int main(void)
{
    Matrix* A = createMatrix(4);
    float v;
    int i, j;
    for (i = 0; i < A->d; i++)
    {
        for (j = 0; j < A->d; j++)
        {
            if(i < j)break;
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &v);
            insertMatrix(A, v, i, j);
        }        
    }    
    printMatrix(A);    
    destroyMatrix(A);
    return 0;
}