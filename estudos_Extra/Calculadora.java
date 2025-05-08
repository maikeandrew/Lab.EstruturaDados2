package estudos_Extra;

import java.util.Scanner;

public class Calculadora {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite doi valores: ");
            double a = scanner.nextDouble();
            double b = scanner.nextDouble();
        System.out.print("Escolha a operacao ( + , - , / , * , ^ ): ");
            char op = scanner.next().charAt(0);
            double resultado;
            // Try esta sendo utilizado para capturar os possiveiss erros
            try {
                switch (op){
                    case '+' : resultado = a + b; break;
                    case '-' : resultado = a - b; break;
                    case '*' : resultado = a * b; break;
                    case '/' :
                    //throw aqui esta forcando um erro caso o usuario tente algo invalido
                    // Arithmetic operacoes matematicas invalidas
                        if (b == 0) throw new ArithmeticException(" Divisao por zero!");
                        resultado = a / b; break;
                    case '^': resultado = Math.pow(a, b); break;
                    // IllegalArgument, Quando o argumento e invalido
                    default: throw new IllegalArgumentException("Operacao Invalida!");
                    }
                System.out.printf("Resultado: %.2f\n", resultado);
                } catch (Exception e) {
                System.out.println("Erro: " + e.getMessage());
            }
            scanner.close();
            }
// --> OBS: (ImputMismatch) Quando o tipo de dado lido não corresponde <--
    }

