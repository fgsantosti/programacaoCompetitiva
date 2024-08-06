#include<stdio.h>

int main(){
    int x[10];
    int num;

    for (size_t i = 0; i < 10; i++)
    {
        scanf("%d", &x[i]);
    }

    for (size_t i = 0; i < 10; i++)
    {
        if(x[i]<=0) printf("X[%d] = 1\n", i,x[i]);
        else printf("X[%d] = %d\n", i,x[i]);

    }
    return 0;
}