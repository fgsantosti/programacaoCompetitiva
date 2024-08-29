#include <stdio.h>
#include <string.h>

#define max_pessoas 5
#define max_nome 100
#define max_telefone 14

int main() {
    char names[max_pessoas][max_nome];
    char telefones[max_pessoas][max_telefone];

    // Entrada dos nomes
    for (int i = 0; i < max_pessoas; i++) {
        printf("Digite o nome completo da pessoa %d: ", i + 1);
        fgets(names[i], max_nome, stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // Remove o caractere de nova linha

        printf("Digite o telefone da pessoa %d: ", i + 1);
        fgets(telefones[i], max_telefone, stdin);
        telefones[i][strcspn(telefones[i], "\n")] = '\0'; // Remove o caractere de nova linha
    }

    // Exibição dos nomes cadastrados
    printf("\nNomes cadastrados:\n");
    for (int i = 0; i < max_pessoas; i++) {
        printf("Pessoa %d: %s\n", i + 1, names[i]);
        printf("Numero %d: %s\n", i + 1, telefones[i]);
    }

    return 0;
}
