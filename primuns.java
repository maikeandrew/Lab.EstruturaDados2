import java.util.Scanner;

public class primuns {

    public static boolean ehPrimo( int n ) {
        if (n <= 1){
            return false;
        } else if (n == 2) {
            return true;
        }

        for (int i = 2; i * i <= n; i++){
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        System.out.println("Digite o numero de inicio: ");
        int n1 =  scanner.nextInt();
        System.out.println("Digite o numero final: ");
        int n2 = scanner.nextInt();

        System.out.println("Numeros primos entre" + n1 + " e " + n2 + ":");
        for (int i = n1; i <= n2; i++){
            if (ehPrimo(i)){
                System.out.print(i + " ");
            }
        }
    }
}
