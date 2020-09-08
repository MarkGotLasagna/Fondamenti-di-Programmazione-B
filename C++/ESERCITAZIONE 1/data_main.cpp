
#include <iostream>

using namespace std;

/* memorizzare la classe Data in un file con nome esercizio_1.cpp
posto nella stessa cartella in cui è presente il file di questo programma.
La direttiva di preproccising #include "esercizio_1.cpp" si occuperà
di caricare tutto il contenuto del file esattamente nel punto  in cui si trova
la direttiva stessa.
In alternativa, inserire direttamente la dichiarazione della classe Data
al posto della direttiva #include "esercizio_1.cpp".

Nel primo caso fare l'upload su elly di entrambi i file (data_main.cpp e
esercizio_1.cpp; nell'altro caso fare l'upload soltanto del file data_main.cpp).
*/

#include "esercizio_1.cpp"

int main() {
    Data d1(9,12,2010);  // crea un oggetto di classe Data
    Data d2(3,1,2011);   // crea un oggetto di classe Data
    Data d3;
    
    if (d1.data_minore(d2)) cout << "d1 < d2" << endl;
	else cout << "d2 < d1" << endl;
	if (d1.data_uguale(d2)) cout << "d1 == d2" << endl;
	else cout << "d1 != d2" << endl;
		
	int differenza_giorni;
	differenza_giorni = d2.sottrai_data(d1);
	cout << "\nLa differenza di giorni tra 3/1/2011 e 9/12/2010 e' " << differenza_giorni << endl;
	
	d3 = d1.somma_giorni(differenza_giorni);	
	cout << "la data ";
	d3.stampa_data(); 
    cout << " deve essere uguale alla data ";
	d2.stampa_data();
	cout << endl;
			
	int anno = d2.get_anno();
	if  (d2.bisestile()) cout << "l'anno " << anno << " e' bisestile" << endl;
	else cout << "\nL'anno " << anno << " non e' bisestile" << endl;
	
    Data data_oggi;
	cout << "Immetti la data 6 3 2020: ";
    data_oggi.leggi_data();
    cout << "la data immessa e' ";
	data_oggi.stampa_data();
	cout << endl << endl;
    
    Data data_errata1(3,13,2018);
	Data data_errata2(29,2,2013);   
	cout << "Valore data errata ";
	data_errata2.stampa_data(); 
	cout << endl;
	
    //system("pause");    
    return 0;    
}

/* traccia esecuzione

d1 < d2
d1 != d2

La differenza di giorni tra 3/1/2011 e 9/12/2010 e' 25
la data 3/1/2011 deve essere uguale alla data 3/1/2011

L'anno 2011 non e' bisestile
Immetti la data 6 3 2020: 6 3 2020
la data immessa e' 6/3/2020

Data errata
Data errata
Valore data errata 0/0/0

*/
