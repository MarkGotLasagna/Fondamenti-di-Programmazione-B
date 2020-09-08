/* Copiare il contenuto di un file in un altro.
   Nome del file da copiare: "sorgente.txt".
   Nome del nuovo file: "destinazione.txt"
*/

#include <fstream>
#include <iostream>

using namespace std;

void copia_file(istream& sorg, ostream& dest) {
   char c;
   do { 
      c = sorg.get();
      if (sorg.eof()) break;
      dest.put(c);
   } while (true);
   return;
}
    
int main() {
   // Apre un file per l'input.
   ifstream in_file;
   in_file.open("sorgente.txt");
   // Controllo errori di apertura del file.
   if (in_file.fail()) {
      cout << "Il file non esiste!" << endl;    
      system("pause");
      return 0;
   }

   // Apre un file per l'output.  
   ofstream out_file;
   out_file.open("destinazione.txt");
  
   copia_file(in_file,out_file); 
 
   in_file.close();
   out_file.close();
 
   // stampa il file "risultati.txt" sullo std output  
   in_file.clear();
   in_file.open("sorgente.txt");
      
   copia_file(in_file,cout); 

   in_file.close();
  
   system("pause");
   return 0;
}
