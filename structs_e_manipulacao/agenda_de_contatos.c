#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Contato
{
    char nome[50];
    char telefone[15];
};

#define TAMANHO_INICIAL_AGENDA 5

//Protótipos das Funções

void adicionarContato(struct Contato **agenda, int *totalContatos, int *capacidadeAgenda);
void listarContatos(struct Contato *agenda, int totalContatos);
void buscarContato(struct Contato *agenda, int totalContatos);
void limparBuffer();

//Função Principal 

int main()
{

    struct Contato *agenda;

    int totalContatos = 0;

    int capacidadeAgenda = TAMANHO_INICIAL_AGENDA;

    int opcao;

    agenda = (struct Contato *)malloc(capacidadeAgenda * sizeof(struct Contato));
    if (agenda == NULL)
    {
        printf("Erro: Nao foi possivel alocar memoria inicial para a agenda.\n");
        return 1;
    }

    do
    {
        printf("\n--- Minha Agenda de Contatos ---\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Todos os Contatos\n");
        printf("3. Buscar Contato por Nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            adicionarContato(&agenda, &totalContatos, &capacidadeAgenda);
            break;
        case 2:
            listarContatos(agenda, totalContatos);
            break;
        case 3:
            buscarContato(agenda, totalContatos);
            break;
        case 0:
            printf("Saiu da agenda.\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    free(agenda);
    agenda = NULL;

    return 0;
}

// Implementação das Funções

// Função auxiliar para limpar o buffer de entrada

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Função para adicionar um novo contato

void adicionarContato(struct Contato **agenda, int *totalContatos, int *capacidadeAgenda)
{
    printf("\n-- Adicionar Novo Contato --\n");

    if (*totalContatos >= *capacidadeAgenda)
    {
        *capacidadeAgenda += 5; 
        struct Contato *novaAgenda = (struct Contato *)realloc(*agenda, *capacidadeAgenda * sizeof(struct Contato));

        if (novaAgenda == NULL)
        {
            printf("Erro: Nao foi possivel aumentar a capacidade da agenda.\n");
            return;
        }
        *agenda = novaAgenda;
        printf("Capacidade da agenda aumentada para %d contatos.\n", *capacidadeAgenda);
    }

    printf("Nome do contato: ");
    fgets((*agenda)[*totalContatos].nome, sizeof((*agenda)[*totalContatos].nome), stdin);

    (*agenda)[*totalContatos].nome[strcspn((*agenda)[*totalContatos].nome, "\n")] = 0;

    printf("Telefone: ");
    fgets((*agenda)[*totalContatos].telefone, sizeof((*agenda)[*totalContatos].telefone), stdin);

    (*agenda)[*totalContatos].telefone[strcspn((*agenda)[*totalContatos].telefone, "\n")] = 0;

    (*totalContatos)++;
    printf("Contato adicionado com sucesso!\n");
}

// Função para listar todos os contatos

void listarContatos(struct Contato *agenda, int totalContatos)
{
    printf("\n-- Lista de Contatos --\n");

    if (totalContatos == 0)
    {
        printf("Nenhum contato cadastrado na agenda.\n");
        return;
    }

    printf("%-20s %-15s\n", "Nome", "Telefone");
    printf("------------------------------\n");

    for (int i = 0; i < totalContatos; i++)
    {
        printf("%-20s %-15s\n",
               agenda[i].nome,
               agenda[i].telefone);
    }
    printf("------------------------------\n");
}

// Função para buscar um contato por nome

void buscarContato(struct Contato *agenda, int totalContatos)
{
    printf("\n--- Buscar Contato por Nome ---\n");

    if (totalContatos == 0)
    {
        printf("Nenhum contato cadastrado para buscar.\n");
        return;
    }

    char nomeBusca[50];
    bool encontrado = false;

    printf("Digite o nome do contato a ser buscado: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0; 

    for (int i = 0; i < totalContatos; i++)
    {
        if (strcmp(agenda[i].nome, nomeBusca) == 0)
        {
            printf("\nContato encontrado!\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        printf("Contato com o nome '%s' nao encontrado na agenda.\n", nomeBusca);
    }
}