#include <stdio.h>

int paresAB(int a, int b){
    return a%2==0&&b%2==0;
}

int main(void)
{
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        if(a == b){
            if(paresAB(a, b)){
                printf("%d\n", a*b);
            }else{
                printf("%d\n", (a+b)-2*(int)(a/2));
            }
        }else{            
            if(a > b){
                printf("%d\n", (a*b)+(int)(a/2));
            }else{
                printf("%d\n", (a*b)+(int)(b/2));
            }
        }
    }
    return 0;
}