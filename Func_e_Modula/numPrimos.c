#include <stdio.h>
#include <stdbool.h>

bool numPrimo(int n){
    if (n <= 1){
        return false;
    }

    if (n == 2){
        return true;
    }

    if (n%2 == 0){
        return false;
    }

    for (int i = 3; i * i <= n; i += 2){
        if (n%i ==0){
            return false;
        }
    }
    return true;
}

int main(){
    int nInicial, nFinal;

    printf("Digite o numero inicial do intervalo: ");
    scanf("%d", &nInicial);

    printf("Digite o numero final do intervalo: ");
    scanf("%d", &nFinal);

    if (nInicial > nFinal) //Garante que sejam diferentes
    {
        int dif = nInicial;
        nInicial = nFinal;
        nFinal = dif;
    }

    printf("\nNumeros primos entre %d e %d:\n", nInicial, nFinal);

    for (int i = nInicial; i <= nFinal; i++){
        if (numPrimo(i)){
            printf("%d\n", i);
        }
        
    }
    
}