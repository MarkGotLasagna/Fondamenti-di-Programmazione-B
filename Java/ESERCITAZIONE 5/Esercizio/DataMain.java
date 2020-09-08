public class DataMain {
    
    public static void main (final String[] args) 
    {
          final Data a = new Data(9,9,2015);  // test costruttori
          final Data b = new Data(5,5,2016); 
          final Data c = new Data();
                
          System.out.println("La prima data e' " + a.converti());  // test del metodo toString
          System.out.println("La seconda data e' " + b.converti());  
          System.out.println("La terza data e' " + c.converti());  
          
          if (a.confronta(b) == -1)                             // test del metodo precede
              System.out.println("La data " + a.converti() + 
                                 " precede la data " + b.converti());
          else
              System.out.println("La data " + a.converti() + 
                                 " non precede la data " + b.converti());
                   
          final Data aa = new Data(9,9,2015);          
          if (a.confronta(aa) == 0)                             
              System.out.println("Le date " + a.converti() + " e " + 
                                 aa.converti() + " coincidono");
          else
              System.out.println("La due date sono diverse");
                  
          final Data d = new Data(39,9,2015);      // test errore data
          System.out.println("La quarta data e' " + d.converti());                                             

    }
}

/* Traccia esecuzione
  
La prima data e' 9/9/2015
La seconda data e' 5/5/2016
La terza data e' 0/0/0
La data 9/9/2015 precede la data 5/5/2016
Le date 9/9/2015 e 9/9/2015 coincidono
Data non valida
La quarta data e' 0/0/0

*/



