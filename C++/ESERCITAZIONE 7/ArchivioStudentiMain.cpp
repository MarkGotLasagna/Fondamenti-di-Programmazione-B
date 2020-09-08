#include <iostream>
#include <string>

using namespace std;

#include "esercizio_7.cpp"

int main()
{
    string nome = "Mario", cognome = "Bianchi";
    Studente a1(nome,cognome);     // test costruttore Studente   
    cout << "\nStudente 1:";  
    a1.stampa(cout);
    a1.set_data(15,5,1997);        // test "setter" di Studente
    a1.set_matricola(12345);
    a1.set_email("mario.bianchi@gmail.com");
  
    Studente a2("Carla","Verdi");  
    a2.set_data(15,8,1996);   
    a2.set_matricola(67891);
     
    ArchivioStudenti A;           // test costruttore s.p. Insiemestudenti   
    
    cout << "\n\nElenco studenti iniziale: ";  // test stampa elenco studenti
    A.stampa(cout);               

    try {                        
       cout << "\n\nAggiungi studente 1:";  
       a1.stampa(cout);                  // test metodo stampa di Studente
       A.aggiungi(a1);                   // test aggiungi

       cout << "\n\nAggiungi studente 2:";  
       a2.stampa(cout);                    
       A.aggiungi(a2);

       cout << "\n\nProva ad aggiungere ancora studente 1:" << endl;  // test stampa elenco studenti
       A.aggiungi(a1);
    }
    catch(string s) {
            cout << "Errore: " << s << endl;
    } 
    
    cout << "\nElenco studenti attuale:";  
    A.stampa(cout);                 

    try {
       cout << "\nRimuovi studente 1:" << endl;  
       A.rimuovi("Mario","Bianchi");           // test rimuovi
    
       cout << "\nElenco studenti aggiornato:";  
       A.stampa(cout);                 
  
       cout << "\nProva a rimuovere ancora studente 1:" << endl;  
	   A.rimuovi("Mario","Bianchi");   
	}
    catch(string s) {
            cout << "Errore: " << s << endl << endl;
    } 

//    system("pause");
    return 0;
}

/* OUTPUT:

Studente 1:
 Nome : Mario
 Cognome : Bianchi
 Data di nascita : 0/0/0
 Matricola : 0
 Mail : xxx

Elenco studenti iniziale: vuoto

Aggiungi studente 1:
 Nome : Mario
 Cognome : Bianchi
 Data di nascita : 15/5/1997
 Matricola : 12345
 Mail : mario.bianchi@gmail.com

Aggiungi studente 2:
 Nome : Carla
 Cognome : Verdi
 Data di nascita : 15/8/1996
 Matricola : 67891
 Mail : xxx

Prova ad aggiungere ancora studente 1:
Errore: studente gia' presente

Elenco studenti attuale:
 Nome : Carla
 Cognome : Verdi
 Data di nascita : 15/8/1996
 Matricola : 67891
 Mail : xxx

 Nome : Mario
 Cognome : Bianchi
 Data di nascita : 15/5/1997
 Matricola : 12345
 Mail : mario.bianchi@gmail.com

Rimuovi studente 1:

Elenco studenti aggiornato:
 Nome : Carla
 Cognome : Verdi
 Data di nascita : 15/8/1996
 Matricola : 67891
 Mail : xxx

Prova a rimuovere ancora studente 1:
Errore: Studente non presente

*/
