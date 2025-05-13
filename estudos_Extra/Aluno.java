package estudos_Extra;

import java.util.Scanner;

public class Aluno {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o nome do aluno(a): ");
        String nomeAluno = scanner.nextLine().trim();


        System.out.print("Digite as notas: ");
        double nota1 = scanner.nextDouble();
        double nota2 = scanner.nextDouble();
        double nota3 = scanner.nextDouble();

        // calcula das notas
        double media = (nota1 + nota2 + nota3) / 3;

        // Verificacao de aprovacao
        String resultado = media >= 7 ? " foi aprovado! " : " foi reprovado! ";
/*
        if (media >= 7){
           resultado = "Aluno aprovado! ";
        } else {
            resultado = "Aluno reprovado! ";
        }
*/
        System.out.printf(nomeAluno + resultado + "\nSua media: %.1f\n", media);

        scanner.close();
    }
}
