#include <iostream>
#include <string>
//#include <stdlib.h>

using namespace std;

#include "esercizio_4.cpp"

void prova(string s, Insieme<string> X){       // test costruttore di copia (automatico)
  X.remove(s);
  X.add("cavallo");
  return;
  }

int main() {		
  Insieme<string> S1;
  cout << "S1: " << S1 << endl;
  cout << "Cardinalita' di S1: " << S1.size() << endl << endl;
  
  string frase[] = {"il","gatto","e","il","topo"};
  Insieme<string> S2_0(frase,5);
  Insieme<string> S2_1(S2_0);			// test costruttore di copia (esplicito)
  Insieme<string> S2;
  S2 = S2_1;                            // test operatore di assegnamento
  cout << "S2: " << S2 << endl;
  cout << "Cardinalita' di S2: " << S2.size() << endl << endl;
  
  const Insieme<string> empty;          //attenzione: empty � un oggetto const ...
  cout << "Unione di insieme vuoto e S2: " << empty + S2 << endl << endl;

  try {
	S1.add("topo");
  	S1.add("gatto");
  	S1.add("il");
  	S1.add("e");
    cout << "S1: " << S1 << endl;
    cout << "Cardinalita' di S1: " << S1.size() << endl;
        
  	if (S1 < S2 && S2 < S1)
      	cout << "I due insiemi S1 e S2 sono uguali" << endl << endl;
  	else
      	cout << "I due insiemi S1 e S2 sono diversi" << endl << endl;		

  	Insieme<string> S3;
   	S3.add("e");
  	S3.add("il");
  	S3.add("cane");
  	prova("cane",S3);				// test costruttore di copia 
  	cout << "S3: " << S3 << endl;
  	S3 = S1 + S3;	
  	cout << "Unione di S1 e S3: " << S3 << endl;
  	S3.remove("il");                // test remove
  	cout << "S3 ridotto: " << S3 << endl << endl;
  	
	string aux;
	for (int i=0; i<100; i++)
    	{aux = aux + '*';
  	     S3.add(aux);               // test crescita dinamica
		}  	  
	S3.remove("la");                // test gestione eccezioni
   
  }
  catch(string e) {
	 cout << "Eccezione: " << e << endl << endl;
  }  
  catch(...) {
	 cout << "Eccezione non prevista" << endl << endl;
  }  

  //system("pause");
  return 0;
}

/* Output:

S1: {}
Cardinalita' di S1: 0

S2: {il, gatto, e, topo}
Cardinalita' di S2: 4

Unione di insieme vuoto e S2: {il, gatto, e, topo}

S1: {topo, gatto, il, e}
Cardinalita' di S1: 4
I due insiemi S1 e S2 sono uguali

S3: {e, il, cane}
Unione di S1 e S3: {e, il, cane, topo, gatto}
S3 ridotto: {e, cane, topo, gatto}

Eccezione: elemento non presente

--------------------------------
Process exited after 0.1211 seconds with return value 0
Premere un tasto per continuare . . .

*/
