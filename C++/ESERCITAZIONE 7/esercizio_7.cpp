#include <iostream>
#include <string>

using namespace std;

//meglio inizializzare a 0
struct data_di_nascita {
    int giorno = 0;
    int mese = 0;
    int anno = 0;
};

class Persona {
    //visto solo dove dichiarato e nelle classi derivate
    protected:

        string nome;
        string cognome;
        data_di_nascita data1;

    public:

        //costruttore inizializza parametri per nome e cognome
        Persona(string n, string c) {
            nome = n;
            cognome = c;
        }

        //getters & setter
        string GetName() {
            return nome;
        }
        string GetSurname() {
            return cognome;
        }
        data_di_nascita GetDate() {
            return data1;
        }
        void set_data(int g, int m, int a) {
            data1.giorno = g;
            data1.mese = m;
            data1.anno = a;
        }

        void stampa(ostream &f_out) {
            f_out << endl;
            f_out << " Nome: " << this->nome;
            f_out << endl;
            f_out << " Cognome: " << this->cognome;
            f_out << endl;
            f_out << " Data di nascita: " << this->data1.giorno << "/" << this->data1.mese << "/" <<
            this->data1.anno;
            f_out << endl;
        }
};

//derivazione classe
class Studente : public Persona {
    protected:
        
        int mat;    //numero matricola
        string email;   //email matricola

    public:

        Studente() : Persona("","") {
        }
        //costruttore ereditante parametri del costruttore Persona
        Studente (string n, string s) : Persona (n, s) {
            int mat = 0;
        }

        void set_matricola(int m) { //m è il numero matricola
            mat = m;
        }
        void set_email(string e) {  //e è l'email
            email = e;
        }

        void stampa(ostream &f_out) {
            Persona :: stampa(f_out);   //richiamo la funzione di Persona stampa
            f_out << " Matricola: " << this->mat;
            f_out << endl;
            if (this->email.empty()) {
                f_out << " Email: ";
                f_out << "xxx";
            }
            else f_out << " Email: " << this->email;
            f_out << endl;
        }

        bool operator==(Studente x) {
            return (!this->GetName().compare(x.GetName()) && !this->GetSurname().compare(x.GetSurname()));
        }
};

struct elem {   //tipo elemento lista concatenata
    Studente s; //sarebbe s
    elem* punt;
};

class ArchivioStudenti {
    private:

        elem* inizio;   //testa, sarebbe l
        
        bool search(Studente s) {
            elem* w = inizio;   
            while (w != NULL)
            {
                if(!s.GetName().compare(w->s.GetName()) && !s.GetSurname().compare(w->s.GetSurname())) return true;
                w=w->punt;  //prossimo elemento
            }
            return false;
        }

    public:

        ArchivioStudenti() {
            inizio = NULL;
        }

        void add_first(Studente x){
	       	elem* t = new elem;
	        t->s = x;
            t->punt = inizio;
            inizio = t;
			return;
	   	}

        void aggiungi(Studente x){
            if(search(x)) throw string ("Studente gia' in lista");
            if(inizio == NULL) add_first(x);
            else{
            	elem* t = inizio;
             	while(t->punt != NULL)
              	t=inizio->punt;
            	t->punt = new elem;	// alloca il nuovo elemento in fondo alla
             	t->punt->punt=NULL;	// lista e lo inizializza
            	t->punt->s=x;
 			}
			return;
        }

        void remove_first(){
              	if(inizio == NULL) 
					throw string("Lista vuota!");
				Studente x;
              	x = inizio->s;
              	elem* t = inizio;
              	inizio = inizio->punt;
              	delete t;
         	}

        void rimuovi(string n, string c){       // cfr. remove in classe di libreria list
				if(inizio->s == Studente(n, c)){
				    remove_first();
					return;
				}
				elem* t = inizio;
				while(t->punt != NULL){
              		if (t->punt->s == Studente(n, c)){         // t->punt punta all'elemento da rimuovere
              		    elem* next = t->punt->punt;  // next punta all'elemento successivo quello da rimuovere
              		    delete t->punt;
              		    t->punt=next;	             // t->punt ora punta all'elemento successivo quello rimuosso
					    break;
					}
              		else t = t->punt;
              	}
                throw string("Studente non trovato!");
            }

        /*void rimuovi(string n, string c) {
            if (!search(Studente (n, c))) throw string("Studente non trovato!");
            //creo un walker
            elem* w = inizio, *k;   //inizio è l'inizio lista
            while(w != NULL) {  //devo cercare la persona
                //confronto nome e cognome corrispondenti in lista
                //s è un oggetto di tipo Persona
                if (!n.compare(w->s.GetName()) && !c.compare(w->s.GetSurname())) {
                k = w;
                //devo passare al prossimo elemento
                w = w->punt;
                //elimino l'elemento che prima era testa
                delete k;
                //la nuova testa è l'elemento successivo
                inizio = w;
                return;
                }
            w = w->punt; 
            }
        }*/

        void stampa(ostream &f_out) {
            elem* w = inizio;
            if (w == NULL) f_out << " vuoto" <<endl;
            else while(w != NULL) {
                w->s.stampa(f_out);
                w = w->punt;
            }
        }
};
