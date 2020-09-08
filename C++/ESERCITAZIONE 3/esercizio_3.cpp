#include <iostream>

using namespace std;

class StringSet{
	private:
		string S[100];	//crea array di string max 100 lenght
	public:
		StringSet(){
		}
		
		StringSet(string V[], int n)
		{
			for(int i=0; i<n; i++)
				if(contains(V[i]) == false) add(V[i]);
		}
		
		void print(ostream &f_out) const
		{
			f_out << '{';
			for(int i=0; i<size(); i++)
				{
					f_out << S[i];
					if(!S[i+1].empty()) f_out << ',';
				}
			f_out << '}';
		}
		
		void add(string x)
		{
			if(size() < 99)
				{
					if(contains(x) == false)
					{
						S[size()] = x;
					}
				}
			else throw string("Spazio non sufficiente");	//oggetto creato string inizializzato a "Spazio non sufficiente"
		}
		
		int size() const
		{
			int i;
			for(i=0; !S[i].empty(); i++);	//restituisce il numero di stringhe nell'array
			return i;	//ritorna la grandezza dell'array
		}
		
		bool contains(string x) const
		{
			for(int i=0; i<size(); i++)
				if(S[i] == x)
				{
					return true;
				}
			return false;
		}
		
		StringSet operator+(const StringSet &S2) const
		{
			StringSet S3;
			S3 = S2;	//posso, perché non devo controllare che sia contenuto o meno
			for(int i=0; i<size(); i++)
				S3.add(S[i]);
			return S3;
		}
		
		bool operator<(const StringSet &S2) const
		{
			int found=0;
			for(int i=0; i<size(); i++)
				if(S2.contains(S[i]) == true) found++;
			if(found == size()) return true;
			else return false;
		}
};
		
		ostream& operator<<(ostream &f_out, const StringSet &S2)
		{
			S2.print(f_out);
			return f_out;
		}
