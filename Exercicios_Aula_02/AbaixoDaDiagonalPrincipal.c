#include <stdio.h>
#include <stdlib.h>

#define ROWS 12 /* linhas */
#define COLS 12 /* colunas */
#define NOTNULL(x) (x != NULL) 

/*
    funcao que soma todos os elementos abaixo da diagonal principal
    Entradas: 
        float* matrix -> O ponteiro para a matriz original
        int* items -> Ponteiro opcional caso queira somar a quantidade
            de elementos que existe abaixo da diagonal principal.
            Caso não seja necessario esse dado, passe NULL.
    Saida:
        float -> Resultado da soma de todos os elementos
            abaixo da diagonal principal
*/
float somaAbaixoDiagonalPrincipal(float* matrix, int* items){
    float soma = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int offset = ROWS * i + j; /* calculo do offset da memoria */
                                    /* i -> linha | j -> coluna */
            if(i > j){ /* Caso i > j é a condição em que o elemento está abaixo */
                soma += *(matrix + offset); 
                /* caso o ponteiro items for diferente de NULL ele incremente */
                if(NOTNULL(items)) (*items)++;
            }            
        }
    }
    return soma;    
}

/*
    função para calcular a media dos elementos abaixo da diagonal principal
    Entradas:
        float* matrix -> Ponteiro para a matriz original
    Saida:
        float -> Resultado da media dos elementos abaixo da diagonal
            principal
 */
float mediaAbaixoDiagonalPrincipal(float* matrix){
    float soma;
    int items = 0; /*
                    variavel que sera atribuida internamente pelo endereco
                    na funcao somaAbaixoDiagonalPrincipal(..., &items);
                */  
    soma = somaAbaixoDiagonalPrincipal(matrix, &items);    
    return soma/(float)items; 
}

int main(){

    char op; /* S(Soma) ou M(Media) */
    scanf("%c", &op);

    /*
        Sera alocada dinamicamente um espaço de (ROWS * COLS * sizeof(float)) bytes
        na memoria e o retorno da funcao malloc sera um ponteiro do tipo void, o qual
        faremos um cast pro tipo de variavel ponteiro que vamos trabalhar.
    */
    float* M = (float*)malloc(ROWS * COLS * sizeof(float));
    for (int i = 0; i < ROWS*COLS; i++){
        scanf("%f", (M + i)); /* recebendo todos os ROWS * COLS valores */
    }

    /* switch basico entre as opcoes de soma e media */
    switch (op)
    {
        case 'S': {
            printf("%.1f\n", somaAbaixoDiagonalPrincipal(M, NULL));
            break;
        }
        case 'M':{
            printf("%.1f\n", mediaAbaixoDiagonalPrincipal(M));
            break;
        } 
    }  
         
    return 0;
}

