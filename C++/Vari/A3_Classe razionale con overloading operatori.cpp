/*
  Scrivere una classe che implementa il tipo di dato astratto "numero razionale"
  (rappresentato come numeratore/denominatore). Scrivere anche un programma 
  principale di prova che legge da std input due numeri razionali e quindi li somma
  e stampa il risultato.
*/

#include <iostream>

using namespace std;

class Razionale {
   private:
      int n;    // Numeratore.
      int d;    // Denominatore.
   public:
      // Inizializzazione
      Razionale() {                   // Costruttore senza parametri 
         n = 0;
         d = 1;
         }
      Razionale(int num, int den) {   // Costruttore con 2 parametri
         n = num;
         if (den == 0) {
            cout << "ATTENZIONE!: denominatore nullo" << endl;
            d = 1;
            }
         else 
            d = den;
         }

      // Legge il numero razionale nella forma `n/d'.
      void leggi(istream& s_in) {
         int num, den;
         char sep;
         s_in >> num >> sep >> den;
         n = num;
         if (den == 0) {
            cout << "ATTENZIONE!: denominatore nullo" << endl;
            d = 1;
            }
         else
            d = den;
         return;
         }

      // Stampa il numero razionale nella forma `n/d'.
      void stampa(ostream& s_out) {
         s_out << n << '/' << d;
         return;
         }     

      // Esegue la somma tra 'x' e l'oggetto di invocazione.
      Razionale operator+(Razionale x) {
         Razionale risultato;
         risultato.d = d * x.d;
         risultato.n = n * x.d + x.n * d;
         return risultato;
         }
};

ostream& operator<<(ostream& s_out, Razionale r) {
  r.stampa(s_out);
  return s_out;
}

istream& operator>>(istream& s_in, Razionale& r) {
  r.leggi(s_in);
  return s_in;
}


int main() {
   Razionale a,b,c;  // invocano il costruttore senza parametri
   cout << "Dai la prima frazione (n/d): ";
   cin >> a;
   cout << "Dai la seconda frazione (n/d): ";
   cin >> b;
   c = a + b;
   cout << "La somma e': " << c << endl;
   
//   system("pause");
   return 0;
}
