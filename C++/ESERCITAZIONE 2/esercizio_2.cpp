#include <iostream>

using namespace std;

class Razionale {
   private:
      int n;    // Numeratore.
      int d;    // Denominatore.
      
      int mcd(int x, int y)
      {
      	while(y > 0)
      	{
      		int ris=x%y;
      		x=y;
      		y=ris;
		}
		  return x;
	  }
	  
	  void semplifica()
	  {
	  	int ris = mcd(n, d);
		n = n / ris;
	  	d = d / ris;
	  }
	  
   public:
      // Inizializzazione
      Razionale() {                   // Costruttore senza parametri 
         n = 0;
         d = 1;
         }
         
      Razionale(int num, int den=1) {   // Costruttore con 2 parametri
         n = num;
         if (den == 0) {
            cout << "ATTENZIONE!: denominatore nullo" << endl;
            d = 1;
            }
         else 
            d = den;
            semplifica();
         }

      // Legge il numero razionale nella forma `n/d'.
      void leggi(istream& s_in) {
         int num, den;
         char sep;
         s_in >> num;
         sep = s_in.get();
         if (sep == '\n') den=1;
         else s_in >> den;
         n = num;
         if (den == 0) {
            cout << "ATTENZIONE!: denominatore nullo" << endl;
            d = 1;
            }
         else
            d = den;
        semplifica();
         return;
         }

      // Stampa il numero razionale nella forma `n/d'.
      void stampa(ostream& s_out) {
         if(d == 1) s_out << n;
         else s_out << n << '/' << d;
         return;
         }

      // Esegue la somma tra 'x' e l'oggetto di invocazione.
    	Razionale operator+(Razionale x) {
         Razionale risultato;
         risultato.d = d * x.d;
         risultato.n = n * x.d + x.n * d;
         risultato.semplifica();
         return risultato;
         }
         
    	Razionale operator+(int x) {
    		Razionale risultato;
    		risultato.d = d;
    		risultato.n = n + d*x;
    		risultato.semplifica();
    		return risultato;
		}
         
    	Razionale operator*(Razionale x) {
    		Razionale risultato;
    		risultato.d = d * x.d;
    		risultato.n = n * x.n;
    		risultato.semplifica();
    		return risultato;
		}
		
		Razionale operator*(int x) {
			Razionale risultato;
			risultato.d = d;
			risultato.n = n * x;
			risultato.semplifica();
			return risultato;
		}
		
		bool operator<(Razionale x) {
			float a, b;
			a = (float)n/d;
			b = (float)x.n / x.d;
			if(a < b) return true;
			else return false;
		}
		
		bool operator<(int x) {
			float a;
			a = (float)n / d;
			if(a < x) return true;
			else return false;
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
