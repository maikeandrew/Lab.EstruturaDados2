#include <stdio.h>

int invertNum(int n){
    int numInvertido = 0;
    int dig;

    if (n == 0){
        return 0;
    }

    while (n != 0){
        dig = n % 10;
        numInvertido = numInvertido * 10 + dig;
        n /= 10;
    }

    return numInvertido;
}

int main(){
    int numOrigin, nInvertido;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numOrigin);

    nInvertido = invertNum(numOrigin);

    printf("O numerto original e: %d\n", numOrigin);
    printf("O numero invertido e: %d", nInvertido);

    return 0;
}