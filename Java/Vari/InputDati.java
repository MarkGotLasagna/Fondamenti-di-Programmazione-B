import java.util.Scanner;

public class InputDati {
    public int leggiNat() {
        int x;
        System.out.println("Inserisci un numero >=0: ");
        final Scanner sc = new Scanner(System.in);
        do
            x = sc.nextInt();
        while (x < 0);
        return x;
    }
}