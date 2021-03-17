#include <stdio.h>
#include <stdlib.h>

const int TOTAL = 144;
const int ROW = 12;
int main(){
    char op; int i;
    float* matrix = (float*) malloc(TOTAL*sizeof(float));
    scanf("%c", &op);
    for (i = 0; i < TOTAL; i++)
        scanf("%f", matrix + i);

    float soma = .0f;
    for (i = 0; i < TOTAL; i++){
        int divi = i % (ROW+1);
        if(!divi){
            int j;
            int linha = i / ROW;
            for (j = 0; j < linha; j++){
                float v = matrix[(i-1)-j];
                soma += v;  
            }
            printf("%d\n", linha);
        }
    }
    printf("%.1f\n", soma);    
    
    return 0;
}