#include <iostream>

using namespace std;

class Portamonete
{
	private:
		int c50, e1, e2;
		bool Valid(double valore)	//evito di scrivere if superflui
		{
			return (valore == 0.5 || valore == 1 || valore == 2);
		}

	public:
		Portamonete(int c50, int e1, int e2)	//costruttore
		{
			this->c50=c50;
			this->e1=e1;
			this->e2=e2;
		}
		Portamonete()	//evito di scrivere nuovamente Portamonete
		{
			Portamonete(0, 0, 0);
		}
		bool Inserisci(double valore)	//valore = valore moneta
		{
			if(Valid(valore))
			{
				switch ((int)valore)	//converto double in int
				//convertire double in uno switch non è possibile
				{
					case 2 :  e2++;
					break;
					
					case 1 : e1++;
					break;
					
					default : c50++;
					break;
				}
				return true;
			}
			return false;
		}
		bool Inserisci(double valore, int n)
		{
			for(int i=0; i<n; i++)
			if(!Inserisci(valore)) return false;
			return true;
		}
		double Denaro()
		{
			return c50*0.5 + e1 + e2*2;	//ritorno quanti soldi ho nel portamonete
		}
		void DenaroTipo()
		{
			cout<<" "<<c50<<" "<<e1<<" "<<e2;
		}
};
