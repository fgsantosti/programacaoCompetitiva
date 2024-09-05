#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    char nome[50];
} Agencia;

typedef struct {
    int id;
    char nome[50];
    float saldo;
    Agencia agencia;
} Cliente;


void salvarClienteEmArquivo(Cliente cliente, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    fprintf(arquivo, "%d\n%s\n%.2f\n%d\n%s\n", 
            cliente.id, cliente.nome, cliente.saldo, 
            cliente.agencia.numero, cliente.agencia.nome);
    fclose(arquivo);
}

void lerTodosClientes(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    Cliente cliente;
    while (fscanf(arquivo, "%d\n", &cliente.id) != EOF) {
        fgets(cliente.nome, 50, arquivo);
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
        fscanf(arquivo, "%f\n", &cliente.saldo);
        fscanf(arquivo, "%d\n", &cliente.agencia.numero);
        fgets(cliente.agencia.nome, 50, arquivo);
        cliente.agencia.nome[strcspn(cliente.agencia.nome, "\n")] = '\0';

        printf("ID: %d\n", cliente.id);
        printf("Nome: %s\n", cliente.nome);
        printf("Saldo: %.2f\n", cliente.saldo);
        printf("Agência: %d - %s\n\n", cliente.agencia.numero, cliente.agencia.nome);
    }

    fclose(arquivo);
}

void alterarCliente(int id, Cliente novoCliente, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    Cliente cliente;
    int encontrado = 0;

    while (fscanf(arquivo, "%d\n", &cliente.id) != EOF) {
        fgets(cliente.nome, 50, arquivo);
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
        fscanf(arquivo, "%f\n", &cliente.saldo);
        fscanf(arquivo, "%d\n", &cliente.agencia.numero);
        fgets(cliente.agencia.nome, 50, arquivo);
        cliente.agencia.nome[strcspn(cliente.agencia.nome, "\n")] = '\0';

        if (cliente.id == id) {
            fprintf(temp, "%d\n%s\n%.2f\n%d\n%s\n", 
                    novoCliente.id, novoCliente.nome, novoCliente.saldo, 
                    novoCliente.agencia.numero, novoCliente.agencia.nome);
            encontrado = 1;
        } else {
            fprintf(temp, "%d\n%s\n%.2f\n%d\n%s\n", 
                    cliente.id, cliente.nome, cliente.saldo, 
                    cliente.agencia.numero, cliente.agencia.nome);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(nomeArquivo);
    rename("temp.txt", nomeArquivo);

    if (encontrado) {
        printf("Cliente alterado com sucesso.\n");
    } else {
        printf("Cliente com ID %d não encontrado.\n", id);
    }
}


void deletarCliente(int id, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    Cliente cliente;
    int encontrado = 0;

    while (fscanf(arquivo, "%d\n", &cliente.id) != EOF) {
        fgets(cliente.nome, 50, arquivo);
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
        fscanf(arquivo, "%f\n", &cliente.saldo);
        fscanf(arquivo, "%d\n", &cliente.agencia.numero);
        fgets(cliente.agencia.nome, 50, arquivo);
        cliente.agencia.nome[strcspn(cliente.agencia.nome, "\n")] = '\0';

        if (cliente.id == id) {
            encontrado = 1;
        } else {
            fprintf(temp, "%d\n%s\n%.2f\n%d\n%s\n", 
                    cliente.id, cliente.nome, cliente.saldo, 
                    cliente.agencia.numero, cliente.agencia.nome);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(nomeArquivo);
    rename("temp.txt", nomeArquivo);

    if (encontrado) {
        printf("Cliente deletado com sucesso.\n");
    } else {
        printf("Cliente com ID %d não encontrado.\n", id);
    }
}

int main() {
    Agencia agencia1 = {101, "Agência Central"};
    Cliente cliente1 = {1, "João Silva", 1500.75, agencia1};

    Agencia agencia2 = {102, "Agência Norte"};
    Cliente cliente2 = {2, "Maria Oliveira", 2500.50, agencia2};

    // Salva os clientes no arquivo
    salvarClienteEmArquivo(cliente1, "clientes.txt");
    salvarClienteEmArquivo(cliente2, "clientes.txt");

    // Altera um cliente
    Agencia agenciaAlterada = {103, "Agência Sul"};
    Cliente clienteAlterado = {1, "João da Silva", 2000.00, agenciaAlterada};
    alterarCliente(1, clienteAlterado, "clientes.txt");

    // Deleta um cliente
    deletarCliente(2, "clientes.txt");

    // Lê e exibe todos os clientes
    lerTodosClientes("clientes.txt");

    return 0;
}

