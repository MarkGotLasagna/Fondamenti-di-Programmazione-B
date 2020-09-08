
#include <iostream>
using namespace std;

const int d = 10;

class pila {
public:
  // Costruttore di default.
  pila();

  // Inserisce l'elemento `x' nella pila.
  void push(int x);

  // Estrae un elemento dalla pila.
  int pop();

  // Ritorna `true' se la pila e' vuota;
  // `false' altrimenti
  bool empty() const;

  // Ritorna la capacita' della pila.
  unsigned int capacity() const;

  // Ritorna il numero di elementi contenuti nella pila.
  unsigned int size() const;

private:
  // Puntatore ad un array di int che rappresenta la pila stessa.
  int* A;

  // Indica quanti elementi ci sono nella pila.
  int top;

  // Capacita' della pila.
  int dim;

  // Aumenta la campacita' della pila di d elementi.
  void allarga();
};

pila::pila() {
  A = NULL;
  top = 0;
  dim = 0;
}
  
void
pila::push(int x) {
  if (top == dim)
      allarga();
  A[top] = x;
  top++;
}

int
pila::pop() {
  if (empty())
      throw string("Pila vuota");
  top--;
  return A[top];
}

bool
pila::empty() const {
  return (top == 0);
}

unsigned int
pila::capacity() const {
  return dim;
}

unsigned int
pila::size() const {
  return top;
}

void pila::allarga() {
  int* tmp = new int[dim+d];
  for (int i = 0; i < dim; ++i)
      tmp[i] = A[i];
  delete[] A;
  dim = dim+d;
  A = tmp;
}

int main(){
    try{
	pila p1;			//crea una pila vuota di nome p1		
	cout << "Capacita': " << p1.capacity() << endl;   		//--> 0
	cout << "Numero di elementi: " << p1.size() << endl;   	//--> 0
	p1.push(6);
	p1.push(8);
	p1.push(5);
	cout << "Capacita': " << p1.capacity() << endl;   		//--> 10
	cout << "Numero di elementi: " << p1.size() << endl;   	//--> 3
	int x = p1.pop();
	cout << "Elemento estratto: " << x << endl;  			//--> 5
	cout << "Capacita': " << p1.capacity() << endl;   		//--> 10
	cout << "Numero di elementi: " << p1.size() << endl;   	//--> 2
	while(!p1.empty())
		cout << p1.pop() << ' ';		//--> 8 6
	cout << "Numero di elementi: " << p1.size() << endl;   	//--> 0
	x = p1.pop();    //lancia l'eccezione "Pila vuota"
	cout << "Elemento estratto: " << x << endl;
	}
	catch(string e){
		cout << "Eccezione: " << e << endl;
	}
	return 0;
}

