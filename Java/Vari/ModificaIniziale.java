import java.util.Scanner;

public class ModificaIniziale {
    public static void main(String[] args) {
        String s;
        System.out.println("Inserisci una stringa (terminata da a capo): ");
        Scanner sc=new Scanner(System.in);
        s=sc.nextLine();
        if(s.equals(""))
            System.out.println("\nStringa non valida!");
        else{
            String r;
            char C=Character.toUpperCase(s.charAt(0));
            r=C+s.substring(1);
            System.out.println("\nStringa con maiuscola: "+r);
        }
        return;
    }
}