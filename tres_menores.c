#include <stdio.h>
#include <string.h>

#define NUM_MENORES 3

void mostrarMenoresValores(char nomesPro[][20], float valorPro[], int n);

int main() {
    char nomesPro[5][20];
    float valorPro[5];
    int n = 5;

    
    for (int i = 0; i < n; i++) {
        printf("---DIGITE O NOME DO PRODUTO %d----\n", i + 1);
        fgets(nomesPro[i], sizeof(nomesPro[i]), stdin);
             nomesPro[i][strcspn(nomesPro[i], "\n")] = '\0';
    }

    for (int i = 0; i < n; i++) {
        printf("----DIGITE O VALOR DO PRODUTO %d----\n", i + 1);
        scanf("%f", &valorPro[i]);
               while (getchar() != '\n');
    }
        printf("\n\n---LISTA DE PRODUTOS E VALORES---\n");
    for (int i = 0; i < n; i++) {
        printf("\nNOME->: %s\nVALOR->: %.2f\n", nomesPro[i], valorPro[i]);
    }
      mostrarMenoresValores(nomesPro, valorPro, n);
    return 0;
}


void mostrarMenoresValores(char nomesPro[][20], float valorPro[], int n) {
     int indices[n];
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }
     for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (valorPro[indices[i]] > valorPro[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
    printf("\nOS %d MENORES VALORES SAO->:\n", NUM_MENORES);
    for (int i = 0; i < NUM_MENORES && i < n; i++) {
        int idx = indices[i];
        printf("PRODUTO->: %s - VALOR_>: %.2f\n", nomesPro[idx], valorPro[idx]);
    }
    
}