
#include <iostream> 

using namespace std;

struct persona {
  char nome[50];
  int eta;
};

// Restituisce true se la persona a e' piu' giovane della
// persona b
bool operator<(persona a, persona b) {
   return (a.eta < b.eta);
   }

// Restituisce true se la persona a e la persona b
// hanno la stessa eta'
bool operator==(persona a, persona b) {
   return (a.eta == b.eta);
   }

int main() {
    persona p1,p2;
    cout << "Immetti il nome della prima persona: ";
    cin >> p1.nome;
    cout << "Immetti l'eta' della prima persona: ";	   
    cin >> p1.eta;
    cout << "Immetti il nome della seconda persona: ";
    cin >> p2.nome;
    cout << "Immetti l'eta' della seconda persona: ";	   
    cin >> p2.eta;
    cout << endl;
  
    if (p1 == p2) 
        cout << "Le due persone hanno la stessa eta'" << endl;
    else {
        cout << "Il piu' giovane e' ";
        if (p1 < p2) 
             cout << p1.nome << endl;
        else cout << p2.nome << endl;
    }

  system("pause");
  return 0;
}
