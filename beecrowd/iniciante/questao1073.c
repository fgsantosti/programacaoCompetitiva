#include<stdio.h>

int main(){
    int x[10];
    int num;

    scanf("%d", &num);
  
    for (int i = 0; i < 10; i++)
    {
        printf("N[%d] = %d\n", i,num);
        num += num;
    }
    return 0;
}