package esercizio_6;
public class VettoreStringhe {
    //tipo String[] nome S crea una nuova stringa di grandezza 100
    private String[] S = new String[100];
    private int num;

    public VettoreStringhe() {
        num = 0;    //inizializzo il contatore di stringhe
        return;
    }

    //aggiungo una stringa alla volta quindi non metto String[]
    public void read_add(String s) {
        //controllo grandezza
        if (num == 100) {
            System.out.println("Numero massimo di stringhe raggiunto!");
            return;
        }
        //inseriamo la nostra stringa
        S[num] = s;
        num++;
        return;
    }

    //cerco la stringa piu' corta
    public void find() {
        int index = 0;  //posizione stringa piu' corta
        int l = S[index].length();   //l = numero caratteri stringa piu' corta
        //parto da 1 perche' 0 è gia' la "stringa piu' corta"
        for (int i=1; i<num; i++) {
            if (S[i].length() < l) {
                index = i;
                l = S[i].length();
            }
        }
        System.out.println("La stringa piu' corta e': "+ S[index]);
        return;
    }

    //portiamo il primo carattere di ogni stringa in maiuscolo
    public void CapSet() {
        char cap;   //lettera da portare in maiuscolo
        String V;   //dove metto la nuova stringa con maiuscola
        for (int i=0; i<num; i++) {
            //porto la prima lettera cap,
            //su stringa S[i].charAt(0), in maiuscolo
            cap = Character.toUpperCase(S[i].charAt(0));
            V = cap + S[i].substring(1);    //scrivo il resto non in maiuscolo
            //NON devo scrivere V = S[i] perche' altrimenti
            //avrebbe stampato la stringa con lettera non maiuscola
            //eliminando cio' che abbiamo fatto sopra
            S[i] = V;
        }
        return;
    }

    //print non va a capo
    public void print() {
        System.out.print("[");
        for (int i=0; i<num; i++) {
            if (i != num-1) System.out.print(S[i] + ",");
            else System.out.println(S[i] + "]");
        }
        return;
    }
}