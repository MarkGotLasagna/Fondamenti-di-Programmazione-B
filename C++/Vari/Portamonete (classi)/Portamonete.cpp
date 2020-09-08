#include <iostream>
#include "Portamonete.h"

using namespace std;

int main()
{
	int c50, e1, e2;
	cout<<"Inserisca Le Sue monete ";
	cin>> c50 >> e1 >> e2;
	Portamonete P(c50, e1, e2);
	P.DenaroTipo();
	cout<<"Il Suo capitale complessivo ammonta a "<<P.Denaro();
	return 0;
}
