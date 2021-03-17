#include <stdio.h>

int main(void)
{
    int casosDeTeste;
    scanf("%d", &casosDeTeste); /* primeira entrada são os casos de testes */
    while(casosDeTeste > 0){

        int n, i;
        int soma = 0;
        scanf("%d", &n);
        int dobro = 2 * n;
        for (i = 1; i <= n; i++){
            if(n%i == 0) soma = soma + i;
        }
        
        /* a saida tem que ser igual o problema pede */
        if(soma == dobro) printf("%d eh perfeito\n", n);
        else printf("%d nao eh perfeito\n", n);

        casosDeTeste = casosDeTeste - 1;
    }
    return 0;
}