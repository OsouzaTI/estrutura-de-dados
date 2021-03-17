#include <stdio.h>

int main(){
    int N, X;
    scanf("%d",&N);
    while(N > 0){
        int R = 0;
        scanf("%d",&X);
        while(X > 0){
            R += R==1 ? -1 : 1;
            X--;
        }        
        printf("%d\n", R);
        N--;
    }
    return 0;
}