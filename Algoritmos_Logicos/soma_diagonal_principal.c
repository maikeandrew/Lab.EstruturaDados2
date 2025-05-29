#include <stdio.h>

#define LINHAS 4
#define COLUNAS 4

int main()
{
    int matriz[LINHAS][COLUNAS];
    int somaDiagonalPcl = 0;
    int i, j;

    printf("Digite os elementos da matriz %dx%d:\n", LINHAS, COLUNAS);
    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n Matriz Criada \n");
    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n--- Calculando a Soma da Diagonal Principal ---\n");
    for (i = 0; i < LINHAS; i++)
    {
        somaDiagonalPcl += matriz[i][i];
        printf("Adicionando: matriz[%d][%d] = %d\n", i, i, matriz[i][i]);
    }

    printf("\nA soma da diagonal principal e: %d\n", somaDiagonalPcl);

    return 0;
}