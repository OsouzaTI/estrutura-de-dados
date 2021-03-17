#include <stdio.h>
#include <stdlib.h>

/*
    1 <= N <= 100
        cada numero de 1 a 100 gastariam no maximo
        3 caracteres para serem armazenados
    1 <= K <= 20 ->  20 digitos (20 bytes)    
        cada exclamacao gastaria 1 byte para ser armazenada
        ou seja seriam necessarios ao menos 20 bytes de memoria
        alocada
    
    Ao todo seriam cerca de 3 + 20 = 23bytes no minimo.
*/
#define MAX_K 22 /* indice 0 a 22 = 23bytes */

// ponteiros ¯\_(ツ)_/¯
int contadorExclamacoes(char* str){
    int i = 0, j = 0;
    /* 
        o loop vive ate que o ponteiro aponte para null
        o que em c resulta em falso.
    */  
    while(*(str + i++)){
        /* cada '!' achado, a variavel j recebe 1 */
        if(*(str + i) == '!') ++j;
    }
    return j;
}

int main(){
    int T, // numero de linhas
        N, // Numero
        K; // exclamações
    /* array de char com MAX_K valores possiveis */
    char entrada[MAX_K];
    scanf("%d", &T); /* Numero de entradas do programa */
    for (int i = 0; i < T; i++)
    {
        scanf("%s", entrada); /* ex: 3!!! */
        /* Captura o numero dado na entrada */
        N = atoi(entrada);
        /* captura a quantidade de '!' na entrada e retorna */
        K = contadorExclamacoes(entrada);    
        // controladores
        int contador = 1;
        /* inteiro de 64bits sem sinal inicializada com N */
        unsigned long long int resultado = N;
        /*
            Enquanto (N - (contador * K)) for maior ou
            igual a 1 o loop vive
        */
        while((N - (contador)*K) >= 1){            
            resultado *= (N - (contador)*K);
            contador++;
        }
        printf("%llu\n", resultado);        
    }   
    return 0;
}