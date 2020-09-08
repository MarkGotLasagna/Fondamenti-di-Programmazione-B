#include <iostream>

using namespace std;

class Data{
	private:
		int g, m, a; //giorno, mese, anno
		
		int giorni_mese()
		{
			if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) return 31;
			if (m==4 || m==6 || m==6 || m==9 || m==11) return 30;
			if(bisestile()) return 29;
			else return 28;
		}
		
		bool controlla_data()
		{
			if(m<1 || m>12)
				return false;
			if(g<1 || g>31)
				return false;
			if(giorni_mese()>=g)
				return true;
			return false;
		}
		
		Data avanza_di_un_giorno(Data d)
	    {
	        if(d.g < d.giorni_mese()) // finché il giorno successivo non supera il numero massimo di giorni del mese aumento di uno
	        {
	            d.g = d.g + 1;
	        }
	        else 
	        {
	            d.g = 1;
	            if (d.m == 12) // se il mese è dicembre torno a gennaio
	            {
	                d.m = 1;
	                d.a = d.a + 1;
	            }
	            else // passo al mese successivo
	            {
	                d.m = d.m + 1;
	            }
	        }
	    return d;
	    }
		
	public:
		Data(int giorno, int mese, int anno)
		{
			g = giorno;
			m = mese;
			a = anno;
			if(!controlla_data())
			{
				g = 0;
				m = 0;
				a = 0;
				cout<<"Data errata"<<endl;
			}
		}
		Data()	//inizializzo i dati
		{
			g = 0;
			m = 0;
			a = 0;
		}
		
		bool data_uguale(Data d)
		{
			if(g == d.g && m == d.m && a == d.a) return true;
			else return false;
		}
		
		bool data_minore(Data d)
		{
			if(a < d.a || (m < d.m && a == d.a) || (g < d.g && m == d.m && a == d.a)) return true;
			else return false;
		}
		
		bool bisestile()
		{
			if(a%4 && a%400) return false;
			else return true;
		}
		
		bool leggi_data() 
		{
            cin >> g >> m >> a;
            if (controlla_data() == false) 
			{
                g = m = a = 0;
                return false;
            }
            else return true;
        }
            
        void stampa_data()
		{
            cout << g << '/' << m << '/' << a;
            return;
        }
        
        Data somma_giorni(int n)
        {
        	Data nuova_data;
        	nuova_data.a = a;
        	nuova_data.m = m;
        	nuova_data.g = g;
			for(int i=0; i<n; i++)
        		nuova_data = avanza_di_un_giorno(nuova_data);
        	return nuova_data;
		}
		
		int sottrai_data(Data d)
		{
			if(data_minore(d)) return -1;
			int gg = 0;
			while(!data_uguale(d))
			{
				d = avanza_di_un_giorno(d);
				gg++;
			}
			return gg;
		}
		
		int get_giorno()
		{
			return g;
		}
		
		int get_mese()
		{
			return m;
		}
		
		int get_anno()
		{
			return a;
		}
};
