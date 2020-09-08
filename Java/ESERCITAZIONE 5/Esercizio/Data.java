class Data {
    private int giorno;
    private int mese;
    private int anno;

    public boolean check() {   //controllo della data
        if(mese<1 || mese>12)
            return false;
        if(giorno<1 || giorno>31)
            return false;
        return true;
    }

    public int confronta(Data d){  //confronto data
        if(anno < d.anno || (mese < d.mese && anno == d.anno) || (giorno < d.giorno && mese == d.mese && anno == d.anno))
            return -1;
        else if(giorno == d.giorno && mese == d.mese && anno == d.anno)
            return 0;
        else return 1;
    }

    public String converti(){    //conversione data in g/m/a
        return giorno + "/" + mese + "/" + anno;
    }

    public Data(){
    	giorno = mese = anno = 0;
    };

    public Data(int giorno, int mese, int anno){
        this.giorno = giorno;
        this.mese = mese;
        this.anno = anno;
        if(!check()){   //inizializzo tutti i dati a 0
            this.giorno = 0;
            this.mese = 0;
            this.anno = 0;
            System.out.println("La data non e' valida!");
        }

    }
}