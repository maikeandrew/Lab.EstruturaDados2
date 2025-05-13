package estudos_Extra;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Calculadora {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {

            System.out.print("Digite dois valores: ");
            double a = scanner.nextDouble();
            double b = scanner.nextDouble();

            System.out.print("Escolha a operacao ( + , - , * , / , ^ ): ");
            char op = scanner.next().charAt(0);

            double resultado = calcular(a, b, op);
            System.out.printf("Resultado: %.2f\n", resultado);

        //catch para entradas invalias
        } catch (InputMismatchException e) {
            System.out.println("Erro: Entrada invalida.");
        } catch (ArithmeticException | IllegalArgumentException e) {
            System.out.println("Erro: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
        // Criei um metodo so mente para as operacoes
    private static double calcular(double a, double b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b == 0) {
                    throw new ArithmeticException("Divisao por zero!");
                }
                return a / b;
            case '^':
                return Math.pow(a, b);
            default:
                throw new IllegalArgumentException("Operacao Invalida!");
        }
    }
}
