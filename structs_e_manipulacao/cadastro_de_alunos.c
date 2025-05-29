#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definindo a estrutura (struct) Aluno
struct Aluno
{
    char nome[50];
    int matricula;
    float media;
};

#define MEDIA_APROVACAO 7.0

int main()
{
    int n;
    int i;
    struct Aluno *alunos;

    //Solicita ao usuário o número de alunos

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    //Validação para o número de alunos

    if (n <= 0)
    {
        printf("Numero de alunos invalido. O programa será encerrado.\n");
        return 1;
    }

    //Alocação dinâmica de memoria para o array de alunos

    alunos = (struct Aluno *)malloc(n * sizeof(struct Aluno));

    // Verifica se a alocação de memoria foi bem-sucedida
    if (alunos == NULL)
    {
        printf("Erro: Não foi possível alocar memoria para os alunos.\n");
        return 1;
    }

    // Cadastro dos Alunos

    printf("\n--- Cadastro de Alunos ---\n");
    for (i = 0; i < n; i++)
    {
        printf("\nDados do Aluno %d:\n", i + 1);

        getchar();

        printf("Nome: ");

        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Media: ");
        scanf("%f", &alunos[i].media);
    }

    //Exibição dos Alunos Aprovados

    printf("\n--- Alunos Aprovados (Media >= %.1f) ---\n", MEDIA_APROVACAO);
    bool algumAprovado = false;

    for (i = 0; i < n; i++)
    {
        if (alunos[i].media >= MEDIA_APROVACAO)
        {
            printf("\nNome: %s\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Media: %.2f\n", alunos[i].media);
            algumAprovado = true;
        }
    }

    if (!algumAprovado)
    {
        printf("Nenhum aluno aprovado com media %.1f ou superior.\n", MEDIA_APROVACAO);
    }

    free(alunos);
    alunos = NULL;

    return 0;
}