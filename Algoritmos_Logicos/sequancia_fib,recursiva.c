#include <stdio.h> 


int fibonacciRecursivo(int n) {
    
    if (n == 0) {
        return 0; 
    } else if (n == 1) {
        return 1; 
    }
    
    else {
        return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
    }
}

int main() {
    int n; 
    int resultado;

    printf("Calculadora de Fibonacci \n");
    printf("Digite o valor de 'n' para encontrar o n-esimo numero de Fibonacci: ");
    scanf("%d", &n);

    
    if (n < 0) {
        printf("Por favor, digite um numero inteiro nao negativo.\n");
    } else {
        resultado = fibonacciRecursivo(n); 
        printf("O %d-esimo numero de Fibonacci e: %d\n", n, resultado);
    }

    return 0; 
}