package util;

import java.util.ArrayList;

import model.Model;

public interface Observador {
		
	void consultar ( ArrayList<Param> array);
	void manter ( Model model );
	void salvar ( Model model );
	void remover ( Model model );
	void fechar ( );
	
	
}
