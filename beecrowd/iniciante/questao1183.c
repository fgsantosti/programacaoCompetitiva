
#include <stdio.h>

int main(int argc, char const *argv[])
{   
    int x=12,y=12;
    double v[x][y], soma=0.0, media=0.0;
    char opcao;
    int c, cont=0;
    scanf("%d", &c);
    scanf(" %c", &opcao);

    
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            scanf("%lf", &v[i][j]);
            //v[i][j] = 5.0;
        }
    }

    cont=0;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            if(j>i){
                soma+=v[i][j];
                cont++;
            }
        }
    }
    
    if(opcao=='S'){
        printf("%.1lf\n",soma);
    }else if (opcao=='M') {
        printf("%.1lf\n",soma/cont);
    }
    
   
}