package Funcoes_e_Modularizacao;

import java.util.Scanner;

public class CalcPotencia {

    // Funcao para calcular a potencia
    public static int potencia(int base, int expoente) {

        int resultado = 1;
        for(int i = 0; i < expoente; i++){
            resultado *= base;
        }
        return resultado;
    }
    // Metodo main
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Digite o numero inteiro para a base: ");
        int base = scanner.nextInt();
        System.out.println("Digite o numero inteiro para o expoente: ");
        int expoente = scanner.nextInt();

        // Chamando a funcao e imprimir o resultado

        System.out.println("Resultado: " + potencia(base, expoente));
    }
}
