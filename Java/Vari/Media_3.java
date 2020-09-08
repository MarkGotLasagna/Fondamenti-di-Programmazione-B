//importa la classe libreria Scanner
//Scanner realizza analizzatore di stringhe utilizzato anche per la lettura in input
import java.util.Scanner;

//il nome della classe deve essere necessariamente quello del file
public class Media_3{
    public static void main(String[] args){ //metodo o funzione unica main
        int x,y,z;
        System.out.println("Inserisci 3 numeri interi: ");  //stdout
        //dichiaro una variabile di tipo Scanner di nome sc, creando dinamicamente con new
        //la stringa analizzata sarà quella nello stream input std System.in
        Scanner sc=new Scanner(System.in);
        /*nextInt() è un metodo di Scanner che restituisce il primo numero intero
        nella stringa specificata alla creazione dell'oggetto Scanner su cui nextInt() viene invocata*/
        x=sc.nextInt();
        y=sc.nextInt();
        z=sc.nextInt();
        float m;
        //(float) -> type casting
        m=(float)(x+y+z)/3;
        /*in stampa su stream output la stringa ottenuta dalla concatenazione
        della costante di stringa "La media e': " con la stringa risultante dalla conversione
        a stringa del valore numerico contenuto in m*/
        System.out.println("La media e': "+ m);
        return; //termina esecuzione metodo main
    }
}