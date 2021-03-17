#include <stdio.h>
#include <stdlib.h>

#define ROWS 12
#define COLS 12

int numeroDeElementosAbaixoDaDiagonalPrincipal(){
    int n = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if(i>j)n++;
    return n;    
}

float somaAbaixoDiagonalPrincipal(float** matrix, int imprimir){
    float soma = .0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if(i > j)soma += *(*(matrix+i)+j);    
    if(imprimir)printf("%.1f\n", soma);
    return soma;
}

void mediaAbaixoDiagonalPrincipal(float** matrix){
    float media = somaAbaixoDiagonalPrincipal(matrix, 0);  
    media /= numeroDeElementosAbaixoDaDiagonalPrincipal();
    printf("%.1f\n", media);  
}


int main(){
    int i, j;
    float* matrix[ROWS];
    for (i = 0; i < ROWS; i++)
        matrix[i] = (float*) malloc(COLS * sizeof(float));
    
    char op;
    scanf("%c", &op);

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            scanf("%f", (*(matrix+i)+j));        
    
    switch (op)
    {
        case 83: somaAbaixoDiagonalPrincipal(matrix, 1);break;
        case 77: mediaAbaixoDiagonalPrincipal(matrix);break;
    }

    return 0;
}