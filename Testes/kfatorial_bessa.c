#include <stdio.h>
#include <stdlib.h>

const int Numk = 20;

int exc(char* K){
    int cont = 0, contexc = 0;
    while(K[cont++]){
        contexc++;       
    }
    return contexc;
}

unsigned long long int fatorial(int N, int contexc){
    unsigned long long int fat = N;
    int cont;      /*    (N - i*K)     */
    for(cont = 1; (N - contexc*cont) >= 1; cont++){
        fat = fat * (N - (cont*contexc));
    }
    return fat;
}

int main () {
    int cont, N, T,V;
    char *K = (char*) malloc(Numk*sizeof(char));
    scanf("%d",&T);
    for(cont = 0; cont < T;cont++){
        scanf("%d %s",&N, K);
        printf("%llu\n", fatorial(N,exc(K)));
    }
    return 0;
}