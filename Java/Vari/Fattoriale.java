public class Fattoriale {
    public static void main(final String[] args) {
        int n;
        final InputDati in = new InputDati();
        n = in.leggiNat();
        int r;
        final Calcola calc = new Calcola();
        r=calc.fatt(n);
        System.out.println("Il fattoriale di "+n+" e' "+r);
        return;
    }
}