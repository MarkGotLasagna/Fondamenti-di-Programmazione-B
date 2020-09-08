package esercizio_6;
import java.util.Scanner;

public class VettoreStringheMain {
    public static void main(String[] args) {
        //creo un nuovo oggetto sc della classe Scanner
        Scanner sc = new Scanner(System.in);
        //richiamo il costruttore per creare un oggetto
        VettoreStringhe X = new VettoreStringhe();
        int choice;
        boolean case_1 = false;

        do {
            System.out.println("Scegli una delle seguenti operazioni:\r\n" + " 1. leggi e memorizza\r\n" + " 2. ricerca più corta\r\n" + " 3. ricerca iniziale\r\n" + " 4. stampa\r\n" + " 5. esci\r\n");
            choice = sc.nextInt();  //lettura
            sc.nextLine();  //per le stringhe, in questo caso ometto l'"Invio"
            switch (choice) {
                case 1:
                    System.out.println("Inserisci la tua stringa: ");
                    X.read_add(sc.nextLine());
                    case_1 = true;
                    break;

                case 2:
                    if (!case_1) {
                        System.out.println("Devi almeno dare una stringa!");
                        break;
                    }
                    X.find();
                    break;

                case 3:
                    if (!case_1) {
                        System.out.println("Devi almeno dare una stringa!");
                        break;
                    }
                    X.CapSet();
                    break;

                case 4:
                    X.print();
                    break;

                case 5:
                    System.out.println("Programma terminato!");
                    return;
            }
        }
        while (true);
    }
}