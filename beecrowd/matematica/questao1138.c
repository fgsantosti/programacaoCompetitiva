
#include <stdio.h>

int main(){
    long long a, b, aux, resto;
    int i, contador[10];

    while (1){
        scanf("%lli %lli", &a, &b);
        if(a==0 && b==0) break;

        for (i = 0; i < 10; i++){
            contador[i]=0;
        }
        
        for (i = a; i <= b; i++){
            aux = i;

            while (aux>0){
                resto = aux % 10;
                aux = aux / 10;
                contador[resto]++;
                //printf("%d %d \n", resto, aux);
            }
        }

        for (i = 0; i < 10; i++){
            printf("%d ", contador[i]);
        }        
    }
    
    return 0;
}
