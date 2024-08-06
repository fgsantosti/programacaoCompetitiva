#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 5
#define MAX_NAME_LENGTH 100

int main() {
    char names[MAX_PEOPLE][MAX_NAME_LENGTH];

    // Entrada dos nomes
    for (int i = 0; i < MAX_PEOPLE; i++) {
        printf("Digite o nome completo da pessoa %d: ", i + 1);
        fgets(names[i], MAX_NAME_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // Remove o caractere de nova linha
    }

    // Exibição dos nomes cadastrados
    printf("\nNomes cadastrados:\n");
    for (int i = 0; i < MAX_PEOPLE; i++) {
        printf("Pessoa %d: %s\n", i + 1, names[i]);
    }

    return 0;
}
