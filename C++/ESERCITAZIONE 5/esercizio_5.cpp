#include <iostream>
#include <vector>

using namespace std;

template <class T>

class pila{
    private:
        vector<T> A;    //creo vettore di tipo T nome A
    public:
        pila(int n){
            A.reserve(n);  //crea uno spazio
        }

        void push(T p){
            A.push_back(p); //inserisco un nuovo elemento nella pila
        }

        T pop(){    //restituisce elemento nell'array e elimina
            if (A.empty()){     //eccezione
                throw string("Empty Stack");
            }
            T k=A[getNElem()-1];
            A.pop_back();
            return k;
        }

        bool empty(){   //esegue empty su A
            return A.empty();
        }
        
        //const perche' uso getNElem()
        int getNElem() const{     //ritorna gli elementi di A
            return A.size();
        }

        void stampa(ostream &f_out) const{      //con & indirizzo di mem. parametro
            for (int i = 0; i < this->getNElem(); i++){
                f_out << A[i] << " ";
            }
        }
};
        template <class T>
        ostream& operator<<(ostream &f_out, const pila<T> &S1)
        {
            S1.stampa(f_out);
            return f_out;
        }