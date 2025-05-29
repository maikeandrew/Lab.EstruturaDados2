#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int main()
{
    // Declaração das três matrizes: duas para entrada e uma para o resultado
    int matriz1[LINHAS][COLUNAS];
    int matriz2[LINHAS][COLUNAS];
    int somaMatrizes[LINHAS][COLUNAS];
    int i, j;

    //  Leitura da Matriz 1
    printf("Digite os elementos da primeira matriz (3x3):\n");
    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    //  Leitura da Matriz 2

    printf("\nDigite os elementos da segunda matriz (3x3):\n");
    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    //  Realização da Soma das Matrizes

    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            somaMatrizes[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Exibição das Matrizes

    // Exibe Matriz 1
    printf("\n--- Matriz 1 ---\n");
    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            printf("%4d ", matriz1[i][j]);
        }
        printf("\n");
    }
    // Exibe Matriz 2
    printf("\n--- Matriz 2 ---\n");
    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            printf("%4d ", matriz2[i][j]);
        }
        printf("\n");
    }

    // Exibe Matriz Soma
    printf("\n--- Matriz Soma ---\n");
    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            printf("%4d ", somaMatrizes[i][j]);
        }
        printf("\n");
    }
    return 0;
}
