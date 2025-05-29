#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_MAX 100

int main(){
    int vetor1[TAMANHO_MAX];
    int vetor2[TAMANHO_MAX];
    int intersecao[TAMANHO_MAX];
    int tamanho1, tamanho2;
    int k = 0;
    int i, j;
    bool encontrado;

    //Leitura dos primeiros valores

    printf("Digite o tamanho para o primeiro vetor: ");
    scanf("%d", &tamanho1);
    
    if (tamanho1 <= 0 || tamanho1 > TAMANHO_MAX){
        printf("ERRO: Primeiro vetor, tamanho invalido.\n");
        return 1;
    }
    
    printf("Digite os %d elementos do primeiro vetor:\n", tamanho1);
    for (i = 0; i < tamanho1; i++){
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor1[i]);      
    }
    
    // Leitura do segundo vetor

    printf("Digite o tamanho do segundo vetor (max %d): ", TAMANHO_MAX);
    scanf("%d", &tamanho2);
    
    if (tamanho2 <= 0 || tamanho2 > TAMANHO_MAX) {
        printf("Tamanho inválido para o segundo vetor.\n");
        return 1; // Retorna 1 para indicar erro
    }

    printf("Digite os %d elementos do segundo vetor:\n", tamanho2);
    for (i = 0; i < tamanho2; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor2[i]);
    }
    
    // Encontrando a Intersecao

    for (i = 0; i < tamanho1; i++) {
        encontrado = false;
        for (int l = 0; l < k; l++) { 
            if (vetor1[i] == intersecao[l]) {
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            for (j = 0; j < tamanho2; j++) {
                if (vetor1[i] == vetor2[j]) {                
                    intersecao[k] = vetor1[i];
                    k++; 
                    break; 
                }
            }
        }
    }
    
    // Exibindo a Interseção

    printf("\nElementos comuns (intersecao) entre os dois vetores:\n");
    if (k == 0) {
        printf("Não há elementos em comum.\n");
    } else {
        for (i = 0; i < k; i++) {
            printf("%d ", intersecao[i]);
        }
        printf("\n");
    }

    return 0;

}