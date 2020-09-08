#include <iostream>

using namespace std;

	class int_list{
      	private:
      		struct elem {		// tipo dell'elemento della lista concatenata
           	int info;		
       			elem* punt;
			};
   			elem* l;			// puntatore di inizio della lista concatenata
			int n;				// numero elementi nella lista
   		public:
        	int_list(){			// costruttore senza parametri
		       	l = NULL;
				n = 0;
         	}
      	  
   			void add_first(int x){
	       		elem* t = new elem;
	        	t->info = x;
              	t->punt = l; 		//N.B. campo "l" dell'oggetto di invocazione
              	l = t;
				n++;
				return;
	   		}
	  	        
       	 	int remove_first(){
              	if(l == NULL) 
					throw string("empty list");
				int x;
              	x = l->info;
              	elem* t = l;
              	l = l->punt;
              	delete t;
				n--;
              	return x;
         	}

       	 	void remove_element(int x){       // cfr. remove in classe di libreria list
				if(l->info==x){
				    remove_first();
					return;
				}
				elem* t = l;
				while(t->punt != NULL){
              		if (t->punt->info == x){         // t->punt punta all'elemento da rimuovere
              		    elem* next = t->punt->punt;  // next punta all'elemento successivo quello da rimuovere
              		    delete t->punt;
              		    t->punt=next;	             // t->punt ora punta all'elemento successivo quello rimuosso
					    break;
					}		
              		else t = t->punt;
              	}
              	return;
            }			

			int size() const{
         		return n;
      		}
	       
			bool contains(int x) const{
              	elem* t = l;
             	while(t != NULL){
              		if (t->info == x) return true;
              		else t = t->punt;
              	}
				return false;
         	}


 			int get(int index) const{
              	if(index < 0 || index >= n)
					throw string("out of range index");
              	elem* t = l;
  				for(int i=0;i<index;i++)
					t = t->punt;
				return t->info;
         	}

         	void print(ostream& dest) const{
              	elem* t = l;
				dest << '[';
              	while(t != NULL){
              		dest << t->info;
					if (t->punt != NULL) dest << ',';
             		t = t->punt;
         		}
				dest << ']';
  			}

			void add_last(int x){
              	if(l == NULL) add_first(x);
             	else{
             		elem* t = l;
                 	while(t->punt != NULL)
                  	t=l->punt;
                	t->punt = new elem;	// alloca il nuovo elemento in fondo alla
                 	t->punt->punt=NULL;	// lista e lo inizializza
                	t->punt->info=x;
					n++;
 				}
			  	return;
         	}
		
};

// main di prova

int main() {
        int_list l;
        l.add_first(5);
    	l.add_first(9); 
		l.print(cout);   
		cout << endl;
		 
        int r;
  		r = l.remove_first();
		l.print(cout); 
		cout << endl; 
        cout << "Elemento estratto: " << r << endl << endl;
        
        l.add_first(10);
        l.print(cout);  								// --> [10,5]
       	cout << endl;
		cout << "Elemento di indice 0: " << l.get(0) << endl;  // --> 10
       	cout << "Elemento di indice 1: " << l.get(1) << endl;  // --> 5
       	
 		l.add_last(15);
        l.print(cout);  								// --> [10,5,15]
   	    cout << endl;

        int_list l1;
		int x,y,z;
        cout << "Dai tre elementi da inserire: ";
        cin >> x;
        l1.add_first(x);
        cin >> y;
        l1.add_first(y);
        cin >> z;
        l1.add_first(z);
        cout << "Inseriti " << l1.size() << " elementi" << endl;
        l1.print(cout);
        cout << endl;
		 		          
        cout << "Elemento di indice 1: " << l1.get(1)  << endl;
        cout << "Elemento di indice 2: " << l1.get(2)  << endl;       
        x = l1.remove_first();
        l1.print(cout);
        cout << endl;
		cout << "Elemento di indice 1: " << l1.get(1)  << endl;		 

        l1.add_last(17);
        l1.print(cout);
        cout << endl;
         
        int e;
        cout << "Dai un elemento da cercare ed eventualmente togliere: ";
        cin >> e;
        if (l1.contains(e)) {
                cout << e << " appartiene" << endl;
                l1.remove_element(e);
		}
        else   cout << e << " non appartiene" << endl;
        l1.print(cout);     
         
//       system("pause");
        return 0;
}

/* Prova esecuzione

[9,5]
[5]
Elemento estratto: 9

[10,5]
Elemento di indice 0: 10
Elemento di indice 1: 5
[10,5,15]
Dai tre elementi da inserire: 4 6 8
Inseriti 3 elementi
[8,6,4]
Elemento di indice 1: 6
Elemento di indice 2: 4
[6,4]
Elemento di indice 1: 4
[6,4,17]
DaDai un elemento da cercare ed eventualmente togliere: 4
4 appartiene
[6,17]

Premere un tasto per continuare . . .

*/
