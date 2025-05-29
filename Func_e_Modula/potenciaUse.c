#include <stdio.h>

int CPotencia(int base, int expoente){

    int res = 1;

    if (expoente < 0 ){
        printf("Erro: Expoente negativo\n");
        return 0;
    }
    if (expoente == 0){
        return 1;
    }
    for (int i = 0; i < expoente; i++){
        res *= base;
    }

    return res;
}

int main(){
    int base, expoente;
    int res_pontencia;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente (Inteiro nao negativo): ");
    scanf("%d", &expoente);

    res_pontencia = CPotencia(base, expoente);

    if (expoente >= 0) {
        printf("%d elevado a %d e: %d\n", base, expoente, res_pontencia);
    }

    return 0;
}