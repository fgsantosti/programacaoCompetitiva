#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 5
#define MAX_NAME_LENGTH 100

void inserirCliente(char names[MAX_PEOPLE][MAX_NAME_LENGTH], int *cpfs, float *saldos){
    // Entrada dos nomes
    for (int i = 0; i < MAX_PEOPLE; i++) {
        printf("Digite o nome completo da pessoa %d: ", i + 1);
        fgets(names[i], MAX_NAME_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // Remove o caractere de nova linha
        
        printf("Digite o CPF do cliente: ");
        scanf("%d", &cpfs[i]);
        getchar(); // Consome o caractere de nova linha deixado no buffer após scanf

        printf("Digite o saldo do cliente: ");
        scanf("%f", &saldos[i]);
        getchar(); // Consome o caractere de nova linha deixado no buffer após scanf
    }
}

void listarClientes(char names[MAX_PEOPLE][MAX_NAME_LENGTH], int *cpfs, float *saldos){
    // Exibição dos nomes cadastrados
    printf("\nNomes cadastrados:\n");
    for (int i = 0; i < MAX_PEOPLE; i++) {
        printf("Pessoa %d: %s\n", i + 1, names[i]);
        printf("CPF do cliente: %d\n", cpfs[i]);
        printf("Saldo do cliente: %f\n", saldos[i]);
    }
}

int main() {
    char names[MAX_PEOPLE][MAX_NAME_LENGTH];
    int cpfs[MAX_PEOPLE];
    float saldos[MAX_PEOPLE];

    inserirCliente(names, cpfs, saldos);
    listarClientes(names, cpfs, saldos);
    return 0;
}