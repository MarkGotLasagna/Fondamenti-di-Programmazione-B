package esempiGUI_conLayout;

import java.awt.*;
import javax.swing.*;
import javax.swing.border.TitledBorder;

public class Es6_Calcolatrice extends JFrame {	

	private JTextField primoOp, secondoOp;	
	private JLabel ris;

	public Es6_Calcolatrice() {
		
		setTitle("Operazioni Aritmetiche");
        setSize(300,300);
        setLocation(200,100);      
        setLayout(new BorderLayout());
        
		JPanel pan1 = new JPanel();
		pan1.setLayout(new FlowLayout());
		this.add(pan1, BorderLayout.SOUTH);
			
		Es6_GestoreBottoni g = new Es6_GestoreBottoni(this);
		
		JButton btnEsci = new JButton("Esci");
		pan1.add(btnEsci);
		btnEsci.addActionListener(g);       

		JPanel pan2 = new JPanel();    
		pan2.setLayout(new BorderLayout());
		this.add(pan2, BorderLayout.NORTH);			
		
		JPanel pan2_1 = new JPanel();
		pan2_1.setBorder(new TitledBorder("Operazioni"));		
		pan2_1.setLayout(new GridLayout(3,1,0,10));
        pan2.add(pan2_1,BorderLayout.EAST);
        
		JButton btnSomma = new JButton("Somma");		
		pan2_1.add(btnSomma);
		btnSomma.addActionListener(g);       
		JButton btnProdotto = new JButton("Prodotto");		
		pan2_1.add(btnProdotto);
		btnProdotto.addActionListener(g);       
		JButton btnCancella = new JButton("Cancella");		
		pan2_1.add(btnCancella);
		btnCancella.addActionListener(g);       

		JPanel pan2_2 = new JPanel();
		pan2_2.setBorder(new TitledBorder("Dati"));		
		pan2_2.setLayout(new GridLayout(6,1));
        pan2.add(pan2_2,BorderLayout.WEST);
        
        pan2_2.add(new JLabel("Primo operando"));
		primoOp = new JTextField();
		pan2_2.add(primoOp);
        pan2_2.add(new JLabel("Secondo operando"));
		secondoOp = new JTextField();
		pan2_2.add(secondoOp);		
	    pan2_2.add(new JLabel("Risultato"));
		ris = new JLabel("",JLabel.CENTER);
		pan2_2.add(ris);  // il valore della label sara' calcolato

	}
	
	public void somma() {
		String testo = primoOp.getText();
		double x = Double.parseDouble(testo);

		testo = secondoOp.getText();		
		double y = Double.parseDouble(testo);

		double r = x + y;		
		testo = Double.toString(r);		
		ris.setText(testo);		
	}

	public void prodotto() {
		String testo = primoOp.getText();		
		double x = Double.parseDouble(testo);

		testo = secondoOp.getText();		
		double y = Double.parseDouble(testo);

		double r = x * y;		
		testo = Double.toString(r);		
		ris.setText(testo);
	}
	
	public void cancella() {
		primoOp.setText("");		
		secondoOp.setText("");		
		ris.setText("");
	}
	
	public void esci() {
		System.exit(0);
	}
}
