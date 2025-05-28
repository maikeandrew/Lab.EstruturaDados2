package Funcoes_e_Modularizacao;

import java.util.Scanner;

public class inversoNumero {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Recebendo o tamanho do array
        System.out.print("Digite o tamanho do array: ");
        int tamanho = scanner.nextInt();

        // Declaracao e construcao do array
        int[] numeros = new int[tamanho];


        for (int i = 0; i < tamanho; i++) {
            System.out.print("Digite o elementos do array " + (i + 1) + ": ");
            numeros[i] = scanner.nextInt();
        }

        //Exibindo os valores
        System.out.print("O array original e: ");
        for (int i = 0; i < tamanho; i++) {
            System.out.print(numeros[i] + " ");
        }
        System.out.println();

        System.out.print("O array inverso e: ");
        for (int i = tamanho - 1; i >= 0; i--) {
            System.out.print(numeros[i] + " ");
        }
        scanner.close();

    }
}
