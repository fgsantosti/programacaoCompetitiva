#include<stdio.h>

int main(){
    int tam = 100;
    float x[tam];
    int num;

    for (int i = 0; i < tam; i++)
    {
        scanf("%f", &x[i]);
    }
   
  
    for (int i = 0; i < tam; i++)
    {
        if(x[i]<=10)
            printf("A[%d] = %.1f\n", i,x[i]);
        
    }
    return 0;
}