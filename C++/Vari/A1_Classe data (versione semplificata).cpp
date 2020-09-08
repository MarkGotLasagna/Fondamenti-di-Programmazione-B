/* Leggi una data (G M A) da std input e se corretta
stampala su std output.
Realizzare la nozione di data come classe.
*/

#include <iostream>

using namespace std;

class data {
    private:
        int g;
        int m;
        int a;
        
        // true se l'anno (campo a) e' bisestile
        bool bisestile()
            {}   // DA REALIZZARE!
            
        // restituisce il numero di giorni del mese (campo m)
        // es.: se m=4, restituisce 30
        int giorni_del_mese()
            {}   // DA REALIZZARE!
         
        // true se la data e' corretta
        bool controlla_data()
            {}   // DA REALIZZARE!

    public:
        bool leggi_data() {
            cin >> g >> m >> a;
            if (controlla_data() == false) {
                g = m = a = 0;
                return false;
                }
            else return true;
            }
            
        void stampa_data() {
            cout << g << '/' << m << '/' << a;
            return;
            }
        // INSERIRE QUI EVENTUALI ALTRE FUNZIONI PROPRIE DELLA CLASSE data        
};

int main() {
    data d1;  // crea un oggetto di classe data
    cout << "Dai una data (g m a): ";
    bool ok;
    ok = d1.leggi_data();
    if (!ok) cout << "Errore nella data" << endl;
    else {
         cout << "La data letta e' ";
         d1.stampa_data();
         cout << endl;
         }

    system("pause");
    
    return 0;    
}
