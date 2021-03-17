#include <stdio.h>
#include <stdlib.h>

#define ROWS 12
#define COLS 12
float posicaoNaMatriz(int x, int y, float* matrix){
    /* resumo do resumo */
    return *(matrix + (ROWS * x + y));
}

float somaAbaixoDiagonalPrincipal(float* matrix, int* n){
    float soma = 0.0;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++)
        {
            if(i <= j)continue; if(n)(*n)++;
            soma += posicaoNaMatriz(i, j, matrix);
        }            
    }
    return soma;
}

int main(){
    int n_elementos = (ROWS*COLS*sizeof(float))/sizeof(float) /* numero de elementos do vetor */,
        i = -1; /* iterando o vetor */ 
    float* matrix = (float*) malloc(ROWS * COLS * sizeof(float));

    char op;
    scanf("%c", &op);
    while(++i < n_elementos) scanf("%f", (matrix+i));

    if(op == 'S'){
        printf("%.1f\n", somaAbaixoDiagonalPrincipal(matrix, NULL));
    }else if(op == 'M'){        
        int numerosAbaixoDaDiagonal = 0;
        float soma = somaAbaixoDiagonalPrincipal(matrix, &numerosAbaixoDaDiagonal);
        printf("%.1f\n", soma/(float)numerosAbaixoDaDiagonal); 
    }
    return 0;
}