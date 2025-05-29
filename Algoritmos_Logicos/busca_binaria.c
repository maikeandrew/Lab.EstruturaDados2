#include <stdio.h>
#include <stdbool.h>

int buscaBinaria(int vetor[], int tamanho, int valorBuscado)
{
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim)
    {
        meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == valorBuscado)
        {
            return meio;
        }

        else if (valorBuscado > vetor[meio])
        {
            inicio = meio + 1;
        }

        else
        {
            fim = meio - 1;
        }
    }

    return -1;
}

int main()
{

    int meuVetor[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int tamanho = sizeof(meuVetor) / sizeof(meuVetor[0]);
    int valor;
    int posicaoEncontrada;

    printf("Busca Binaria em Vetor Ordenado \n");
    printf("Vetor: {");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d", meuVetor[i]);
        if (i < tamanho - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");

    printf("Digite o valor que deseja buscar no vetor: ");
    scanf("%d", &valor);

    posicaoEncontrada = buscaBinaria(meuVetor, tamanho, valor);

    if (posicaoEncontrada != -1)
    {
        printf("O valor %d foi encontrado na posicao (indice) %d do vetor.\n", valor, posicaoEncontrada);
    }
    else
    {
        printf("O valor %d nao foi encontrado no vetor.\n", valor);
    }

    return 0;
}