#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
    float saldo;
} Cliente;

void salvarClienteEmArquivo(Cliente cliente, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    fprintf(arquivo, "%d\n%s\n%.2f\n", cliente.id, cliente.nome, cliente.saldo);
    fclose(arquivo);
}

Cliente lerClienteDeArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    }

    Cliente cliente;
    fscanf(arquivo, "%d\n", &cliente.id);
    fgets(cliente.nome, 50, arquivo);
    // Remove o caractere de nova linha (\n) do final da string
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
    fscanf(arquivo, "%f\n", &cliente.saldo);
    fclose(arquivo);

    return cliente;
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
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0'; // Remove \n
        fscanf(arquivo, "%f\n", &cliente.saldo);

        if (cliente.id == id) {
            fprintf(temp, "%d\n%s\n%.2f\n", novoCliente.id, novoCliente.nome, novoCliente.saldo);
            encontrado = 1;
        } else {
            fprintf(temp, "%d\n%s\n%.2f\n", cliente.id, cliente.nome, cliente.saldo);
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
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0'; // Remove \n
        fscanf(arquivo, "%f\n", &cliente.saldo);

        if (cliente.id == id) {
            encontrado = 1;
        } else {
            fprintf(temp, "%d\n%s\n%.2f\n", cliente.id, cliente.nome, cliente.saldo);
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

void lerTodosClientes(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    Cliente cliente;
    while (fscanf(arquivo, "%d\n", &cliente.id) != EOF) {
        fgets(cliente.nome, 50, arquivo);
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0'; // Remove o caractere de nova linha
        fscanf(arquivo, "%f\n", &cliente.saldo);

        printf("ID: %d\n", cliente.id);
        printf("Nome: %s\n", cliente.nome);
        printf("Saldo: %.2f\n\n", cliente.saldo);
    }

    fclose(arquivo);
}



int main() {
    Cliente cliente1 = {1, "Pedro Silva", 1500.75};

    salvarClienteEmArquivo(cliente1, "clientes.txt");

    Cliente clienteLido = lerClienteDeArquivo("clientes.txt");

    //printf("ID: %d\n", clienteLido.id);
    //printf("Nome: %s\n", clienteLido.nome);
    //printf("Saldo: %.2f\n", clienteLido.saldo);


    Cliente cliente2 = {2, "João Silva", 1500.75};
    Cliente cliente3 = {3, "Maria Oliveira", 2500.50};

    salvarClienteEmArquivo(cliente2, "clientes.txt");
    salvarClienteEmArquivo(cliente3, "clientes.txt");

    // Lê e exibe todos os clientes
    lerTodosClientes("clientes.txt");
    /*
    Cliente clienteAlterado = {1, "Carlos da Silva", 2000.00};
    alterarCliente(1, clienteAlterado, "clientes.txt");

    deletarCliente(2, "clientes.txt");

    Cliente cliente4 = {4, "Francisco Santos", 1900.75};
    Cliente cliente5 = {5, "Maria Julia Sousa", 5500.50};
    // Salva os clientes no arquivo
    salvarClienteEmArquivo(cliente4, "clientes.txt");
    salvarClienteEmArquivo(cliente5, "clientes.txt");
    */

    // Lê e exibe todos os clientes
    lerTodosClientes("clientes.txt");

    return 0;
}
