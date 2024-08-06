#include <stdio.h>

int main()
{
    int hi, mi, hf, mf;
    scanf("%d %d %d %d", &hi, &mi, &hf, &mf);

    int instanteInicial = (hi*60)+mi;
    int instanteFinal =(hf*60)+mf;
    int duracao;


    if(instanteInicial<instanteFinal){
        duracao = instanteFinal - instanteInicial;
    }else{
        duracao = (24*60 - instanteInicial)+instanteFinal;
    }

    int duracaoHoras = duracao/60;
    int duracaoMinutos = duracao%60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracaoHoras, duracaoMinutos);
    
    
    return 0;
}