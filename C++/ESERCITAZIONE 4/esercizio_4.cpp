#include <iostream>

using namespace std;

template <class T>  //adatto le funzioni per ogni tipo di classe, oggetto, ecc.

class Insieme{
    private:
        T* A;
        int top;
        int dim;
		
		void allarga()
        {
            T* temp=new T[dim+10];
            for(int i=0; i<dim; i++)
            temp[i]=A[i];
            delete[] A;
            A=temp;
            dim=dim+10;
        }
    public:
        Insieme()
        {
            A=NULL;
            top=0;
            dim=0;
        }

        Insieme(T* x, int n)
        {
            A=new T[n];
            top=0;
            dim=n;
            for(int i=0; i<n; i++)
            	add(x[i]);
        }

        Insieme(const Insieme <T> &a)
        {
            top=a.top;
            dim=a.dim;
            A=new T[dim];
            for(int i=0; i<dim; i++)
                A[i]=a.A[i];
        }

        ~Insieme()
        {
            delete[] A;
        }

        int size() const
		{
			return top;
		}
		
		bool contains(T x) const    //classe di nome x
		{
			for(int i=0; i<size(); i++)
				if(A[i] == x)
				{
					return true;
				}
			return false;
		}

        void add(T x)
		{
			if(contains(x) == false)
				{
					if(top==dim)
                    this->allarga();
                    A[top]=x;
                    top++;
		        }
        }

        void remove(T x)
        {
            if(contains(x) == true) //stessa cosa di contains()
            {
                for(int i=0; i<size(); i++)
                    if(A[i] == x)
                    {
                        for(int j=i; j<size(); j++)
                            A[j]=A[j+1];
                            top--;
                    }
            }
            else throw string("Elemento non presente");
        }

        void print(ostream &f_out) const
		{
			f_out << '{';
			for(int i=0; i<size(); i++)
				{
					f_out << A[i];
					if(!(i+1 == top)) f_out << ',';
				}
			f_out << '}';
		}

        Insieme operator+(const Insieme <T> &S2) const
		{
			Insieme <T> k(S2);
            for(int i=0; i<size(); i++)
            {
                k.add(A[i]);
            }
            return k;
		}

        bool operator<(const Insieme &S2) const
		{
			int found=0;
			for(int i=0; i<size(); i++)
            {
                if(S2.contains(A[i]) == true) found++;
            }
			if(found == size()) return true;
			else return false;
		}
		
		Insieme& operator=(const Insieme<T> &a)
		{
			top=a.top;
            dim=a.dim;
            A=new T[dim];
            for(int i=0; i<dim; i++)
                A[i]=a.A[i];
		}
};

        template <class T>
        ostream& operator<<(ostream &f_out, const Insieme <T> &S2)
        {
            S2.print(f_out);
            return f_out;
        }
