#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_DO_VETOR 10

int main(){
    int numeros[TAMANHO_DO_VETOR];
    int i, j; 
    bool numContados;

    printf("Digite 10 numero inteiros: ");
    for (int i = 0; i < TAMANHO_DO_VETOR; i++){
    printf("Numeros %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\n---> Resultado <---\n");

    for (i = 0; i < TAMANHO_DO_VETOR; i++){
        numContados = false;
        for (j = 0; j < i; j++){
            if (numeros[i] == numeros[j]){
                numContados = true;
                break;
            }
        }
        if (!numContados){
            int contador = 0;
    
            for (j = 0; j < TAMANHO_DO_VETOR; j++){
                if (numeros[i] == numeros[j]){
                    contador++;
                }
            }

            printf("O numero %d aparece %d vezes.\n", numeros[i], contador);
        }
    }
    return 0;
}