#include <stdio.h>
#include <string.h>

void ImprimeVet(int Vet[3])
{
    int i;
    for(i = 0; i < 3; i++) {
    printf("%d ", Vet[i]);
    }
}

int main(){
    
    char Texto[5][17];

    for(int i = 0; i < 5; i++) {
        setbuf(stdin, NULL);
        gets(Texto[i]);
    }

    for(int i = 0; i < 5; i++) {
        printf("%s\n", Texto[i]);
    }

    return 0;
}
