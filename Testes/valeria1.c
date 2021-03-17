#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0 

int main(void)
{
	//Nosso programa precisa ponteiro array_nosso que aponte para o tipo inteiro
	//como o tamanho deste array é dinamico, iniciamos em zero, um n = 1 servirá para
	//sair do programa caso encontremos algum valor de entrada igual a zero e assim
	//numero servirá como nosso valor de entrada e i sera nosso iterador no laço for
	int *A, armazenamento = 0, n = true;
	int num, i;
	
	
	while(n != false){	//ou !n												//enquanto n não for igual a zero, executamos este codigo
		printf("insira os valores que serão armazenados no array: ");
		scanf("%d",&num);												//recebemos um número
			
		if (num == false){	//ou !numero									//verifico se ele é igual a zero
			printf("\nvalores inseridos\n");								//se for, ja imprimo a saida
			for(i = 0;i < armazenamento; i++){									//criando um laço e imprimindo o que tiver no array
				printf("%d\n",*(A + i));							//se na primeira entrada for zero, nada aparecerá
			}																//*(array + i) é o mesmo que array[i]
			n=false;														//definimos então que n = 0 e assim saimos do while
		}
		
		if(armazenamento == false){	//ou !tamanho								//comparamos o valor inicial de tamanho. Se igual a zero ou
			A = (int*)malloc(++armazenamento*sizeof(int));				//sendo false, define-se com o malloc o tamanho do array 
			//printf("\nvalor do tamanho: %d\n",tamanho);					//tamanho é incrementado antes da execução do restante do code
		}else{																//agora se ele for diferente de um, realocamos nosso array
			A = (int*)realloc(A, ++armazenamento*sizeof(int));//isso ocorre para todas as vezes depois da primeira. Assim nós
			//printf("\nvalor do tamanho: %d\n",tamanho);					//ficamos aumentando "tamanho" e realocando o tamanho do array
		}																	//dinamicamente, sempre somando previamente ++tamanho
		*(A+(armazenamento-1)) = num; //ou array_nosso[tamanho-1]	//adicionamos ao array o numero passado. tamanho-1 ocorre pq
	}																		//como icrementamos antes (++tamanho), precisamos tirar a diferença
																			// entre o indice atual e o indice que deveria ser 
	free(A);														//por fim libero a memoria																			
    return 0;
}