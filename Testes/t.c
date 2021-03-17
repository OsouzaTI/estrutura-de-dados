#include <stdio.h>
int main(void) {
  int T,i,a;
  int N[1000];
  scanf("%d",&T);
  if(T<=50)
  {
    for(i=0,a=0;i<=999;i++)
    {
 
     printf("N[%d] = %d\n", i,a);
      a++;
     if(a==T){
         a=0;
     }
    }
  }
  
  return 0;
}