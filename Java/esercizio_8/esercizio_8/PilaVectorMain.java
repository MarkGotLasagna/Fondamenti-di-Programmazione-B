package esercizio_8;

public class PilaVectorMain {
  
       public static void main (String[] args) {
            try {                            
              Pila b = new PilaVector();            
              System.out.println("La pila 'b' e' " + b);
              
              b.push("aaa");
              b.push("bbb");
              b.push("ccc");
              System.out.println("La pila 'b' e' " + b);
              
              System.out.println("Elemento tolto dalla pila 'b': " + b.pop());
              if (!b.isEmpty()) System.out.println("La pila 'b' e' " + b);   
              System.out.println("La pila 'b' ha " + b.size() + " elementi");
              
              Pila copiaDi_b = (PilaVector)((PilaVector)b).clone();
              System.out.println("La pila 'copiaDi_b' e' " + copiaDi_b);
              copiaDi_b.pop();
              System.out.println("La pila 'copiaDi_b' e' " + copiaDi_b);
              
              System.out.println("La pila 'b' e' rimasta invariata: " + b);  
              b.clear();
              System.out.println("La pila 'b' e' " + b + "\n");          
              b.pop();
            }        
            catch (PilaVuota e) {  
                System.out.println("Errore: pop su pila vuota\n");
            }
            catch (Throwable e) {    // catch all
                System.out.print("Altre eccezioni: ");
                System.out.println(e);
            }           
        }   
    }


/* Traccia esecuzione 
      
La pila 'b' e' []
La pila 'b' e' [aaa,bbb,ccc]
Elemento tolto dalla pila 'b': ccc
La pila 'b' e' [aaa,bbb]
La pila 'b' ha 2 elementi
La pila 'copiaDi_b' e' [aaa,bbb]
La pila 'copiaDi_b' e' [aaa]
La pila 'b' e' rimasta invariata: [aaa,bbb]
La pila 'b' e' []

Errore: pop su pila vuota

*/

