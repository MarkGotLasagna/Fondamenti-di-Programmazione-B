package esempiGUI_conLayout;

import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Es6_GestoreBottoni implements ActionListener {

	private Es6_Calcolatrice w1;  
    
	public Es6_GestoreBottoni() {
	}
	public Es6_GestoreBottoni(Es6_Calcolatrice f) {
		this.w1 = f;
	}
	
	public void actionPerformed(ActionEvent e) {   
		JButton b = (JButton)e.getSource();		
		if (b.getText().equals("Somma"))
			w1.somma();
		else if (b.getText().equals("Prodotto"))
		   	w1.prodotto();
		else if (b.getText().equals("Cancella"))
		   	w1.cancella();
		else
			w1.esci();
	} 
}
