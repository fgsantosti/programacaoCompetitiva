#include<stdio.h>




int fib(int num){
    long long int numero;
    if (num == 0){
        printf("Fib(0) = 0");
    }else{

    }
    
}

int main(){
    int t,n;
    scanf("%d", &t);
    while (t>0){
        scanf("%d",n);
        if(n>=0 && n<=60)
            fib(n);
    }

    long long int numero;
    numero = 999999999999;
    printf("Valor da variavel: %lld\n", numero);
    return 0;
    return 0;
}