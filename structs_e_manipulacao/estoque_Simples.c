#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto
{
    char nome[50];
    int codigo;
    int quantidade;
    float preco;
};

#define TAMANHO_INICIAL_ESTOQUE 5

void cadastrarProduto(struct Produto **estoque, int *totalProdutos, int *capacidadeEstoque);
void listarProdutos(struct Produto *estoque, int totalProdutos);
void buscarProduto(struct Produto *estoque, int totalProdutos);
void limparBuffer();

// Função Principal

int main()
{

    struct Produto *estoque;

    int totalProdutos = 0;

    int capacidadeEstoque = TAMANHO_INICIAL_ESTOQUE;

    int opcao;

    estoque = (struct Produto *)malloc(capacidadeEstoque * sizeof(struct Produto));
    if (estoque == NULL)
    {
        printf("Erro: Nao foi possivel alocar memoria inicial para o estoque.\n");
        return 1;
    }

    do
    {
        printf("\n--- Sistema de Estoque Simples ---\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Buscar Produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            cadastrarProduto(&estoque, &totalProdutos, &capacidadeEstoque);
            break;
        case 2:
            listarProdutos(estoque, totalProdutos);
            break;
        case 3:
            buscarProduto(estoque, totalProdutos);
            break;
        case 0:
            printf("Saiu do sistema.\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    free(estoque);
    estoque = NULL;

    return 0;
}

// Implementação das Funções

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar um novo produto

void cadastrarProduto(struct Produto **estoque, int *totalProdutos, int *capacidadeEstoque)
{
    printf("\n--- Cadastrar Novo Produto ---\n");

    if (*totalProdutos >= *capacidadeEstoque)
    {
        *capacidadeEstoque += 5;
        struct Produto *novoEstoque = (struct Produto *)realloc(*estoque, *capacidadeEstoque * sizeof(struct Produto));

        if (novoEstoque == NULL)
        {
            printf("Erro: Nao foi possivel aumentar a capacidade do estoque.\n");
            return;
        }
        *estoque = novoEstoque;
        printf("Capacidade do estoque aumentada para %d produtos.\n", *capacidadeEstoque);
    }

    printf("Nome do produto: ");
    fgets((*estoque)[*totalProdutos].nome, sizeof((*estoque)[*totalProdutos].nome), stdin);

    (*estoque)[*totalProdutos].nome[strcspn((*estoque)[*totalProdutos].nome, "\n")] = 0;

    printf("Codigo do produto: ");
    scanf("%d", &(*estoque)[*totalProdutos].codigo);
    limparBuffer();

    printf("Quantidade em estoque: ");
    scanf("%d", &(*estoque)[*totalProdutos].quantidade);
    limparBuffer();

    printf("Preco unitario: ");
    scanf("%f", &(*estoque)[*totalProdutos].preco);
    limparBuffer();

    (*totalProdutos)++;
    printf("Produto cadastrado com sucesso!\n");
}

// Função para listar todos os produtos

void listarProdutos(struct Produto *estoque, int totalProdutos)
{
    printf("\n--- Lista de Produtos no Estoque ---\n");

    if (totalProdutos == 0)
    {
        printf("Nenhum produto cadastrado no estoque.\n");
        return;
    }

    printf("%-20s %-10s %-10s %-10s\n", "Nome", "Codigo", "Qtd.", "Preco");
    printf("--------------------------------------------\n");

    for (int i = 0; i < totalProdutos; i++)
    {
        printf("%-20s %-10d %-10d %-10.2f\n",
               estoque[i].nome,
               estoque[i].codigo,
               estoque[i].quantidade,
               estoque[i].preco);
    }
    printf("-------------------------------------------\n");
}

// Função para buscar um produto pelo código

void buscarProduto(struct Produto *estoque, int totalProdutos)
{
    printf("\n--- Buscar Produto por Codigo ---\n");

    if (totalProdutos == 0)
    {
        printf("Nenhum produto cadastrado para buscar.\n");
        return;
    }

    int codigoBusca;
    printf("Digite o codigo do produto a ser buscado: ");
    scanf("%d", &codigoBusca);
    limparBuffer();

    for (int i = 0; i < totalProdutos; i++)
    {
        if (estoque[i].codigo == codigoBusca)
        {
            printf("\nProduto encontrado!\n");
            printf("Nome: %s\n", estoque[i].nome);
            printf("Codigo: %d\n", estoque[i].codigo);
            printf("Quantidade: %d\n", estoque[i].quantidade);
            printf("Preco: %.2f\n", estoque[i].preco);
            return;
        }
    }

    printf("Produto com codigo %d nao encontrado no estoque.\n", codigoBusca);
}