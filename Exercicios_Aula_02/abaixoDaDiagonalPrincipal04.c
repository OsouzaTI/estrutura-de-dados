#include <stdio.h>
#include <stdlib.h>

#define ROWS 12
#define COLS 12

int estaAbaixoDaDiagonalPrincipal(int offset){
    int linha = offset/ROWS;
    int coluna = offset - (ROWS * linha);
    if(linha > coluna)return 1;
    return 0;
}

int calcularOffset(int n){
    if(n==0)return 0;
    int linha = n/ROWS;
    int coluna = n - linha * ROWS;
    return  ROWS * linha + coluna;// numero de linhas
}

void processamento(char op, float* matrix, float* valor, int nAbaixoDiagonal , int n){
    if(n<(ROWS*COLS)){
        if(estaAbaixoDaDiagonalPrincipal(calcularOffset(n))){
            *valor += *(matrix + n);
            nAbaixoDiagonal++;
        }
        return processamento(op, matrix, valor, nAbaixoDiagonal, ++n);    
    }
    if(op == 'M') *valor /= (float)nAbaixoDiagonal;
}

int main(){
    char op;
    scanf("%c", &op);
    float* matrix = (float*) malloc(ROWS*COLS*sizeof(float));
    for (int i = 0; i < (ROWS*COLS); i++)
        scanf("%f", (matrix+i));   
    float valor = .0f;
    processamento(op, matrix, &valor, 0, 0);
    printf("%.1f\n", valor);
    free(matrix);
    return 0;
}