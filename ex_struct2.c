#include <stdio.h>
#include <string.h>

#define MAX 3

// Definição da estrutura
typedef struct {
  char nome[30];
  int cpf;
  float saldo;
} Pessoa;

// Função para inserir os dados das pessoas
void inserirPessoa(Pessoa P[]) {
  for (int i = 0; i < MAX; i++) {
    printf("Digite o nome completo da pessoa %d: ", i + 1);
    fgets(P[i].nome, sizeof(P[i].nome), stdin);
    P[i].nome[strcspn(P[i].nome, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o CPF do cliente: ");
    scanf("%d", &P[i].cpf);
    getchar(); // Consome o caractere de nova linha deixado no buffer após scanf

    printf("Digite o Saldo do cliente: ");
    scanf("%f", &P[i].saldo);
    getchar(); // Consome o caractere de nova linha deixado no buffer após scanf
  }
}

// Função para imprimir os dados dos clientes
void imprimirClientes(Pessoa P[]) {
  printf("\n--- Lista de Clientes ---\n");
  for (int i = 0; i < MAX; i++) {
    printf("Cliente %d:\n", i + 1);
    printf("Nome: %s\n", P[i].nome);
    printf("CPF: %d\n", P[i].cpf);
    printf("Saldo: %.2f\n", P[i].saldo);
    printf("------------------------\n");
  }
}

int main() {
  Pessoa pessoas[MAX];

  inserirPessoa(pessoas);
  imprimirClientes(pessoas);

  return 0;
}
