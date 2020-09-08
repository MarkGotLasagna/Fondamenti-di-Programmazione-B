package esercizio_8;

import java.util.Vector;

public class PilaVector implements Pila, Cloneable{

    private Vector v = new Vector();

    public PilaVector() {
    }

    public void push(Object x) {
        v.add(x);
        return;
    }

    public Object pop() {
        if(isEmpty()) throw new PilaVuota();
        Object n = v.get(size()-1); //metto size()-1 perche' evito out_of_bounds
        v.remove(size()-1);
        return n;
    }

    public boolean isEmpty() {
        if(size() == 0) return true;
        else return false;
    }

    public int size() {
        return v.size();
    }

    public void clear() {  //svuota la pila
        for (int i=0; i<size()+1; i++) pop();   //size()+1 perche' altrimenti l'eliminazione non avviene
        return;
    } 
    
    //ridefinisco clone() usando @Override
    //faccio copia profonda dell'oggetto
    @Override
    public Object clone() throws CloneNotSupportedException {
        PilaVector a = (PilaVector) super.clone();  //super -> riferimento alla classe superiore
        a.v = (Vector) v.clone();
        return a;
    }

    public String toString() {
        return v.toString();
    }

}