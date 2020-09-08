/* Legge nome e cognome da std input e crea e stampa
l'indirizzo di posta elettronica nel formato
nome.cognome@studenti.unipr.it */

#include <iostream> 

using namespace std;

int main() {
    string nome, cognome;
    
    cout << "Immetti il nome: ";
    cin >> nome;
    cout << "Immetti il cognome: ";	   
    cin >> cognome;
    cout << endl;
    
    string email = nome+'.'+cognome+'@'+"studenti.unipr.it";
    
    cout << "La tua email sara': " << email << endl << endl;
 
    system("pause");
    return 0;
}
