package controller;

import java.util.ArrayList;

import javax.swing.JInternalFrame;

import dao.DaoConta;
import model.Model;
import model.ModelCliente;
import util.Observador;
import util.Param;
import view.ViewConsultarConta;
import view.ViewManterConta;

public class ControllerConta implements Observador {
	
	private DaoConta dao = new DaoConta();	
	private ViewConsultarConta viewConsultar = new ViewConsultarConta(this);
	private ViewManterConta viewManter = new ViewManterConta(this);
	

	public ControllerConta () {
		viewConsultar.setVisible(true);		
	}

	public JInternalFrame getView () {
		return this.viewConsultar;
	}

	@Override
	public void consultar( ArrayList<Param> array) {	
		viewConsultar.mostrar ( dao.consultar ( array )  );		
	}
	
	@Override
	public void manter(Model model) {
		viewManter.mostrar( (ModelCliente)model );		
	}

	@Override
	public void salvar(Model model) {
		viewConsultar.atualizar( (ModelCliente)model, dao.salvar( model ) );		
	}

	@Override
	public void remover(Model model) {
		viewConsultar.remover (  (ModelCliente)model, dao.remover( model ));		
	}

	@Override
	public void fechar() {
		//viewConsultar.setVisible(false);			
	}

}
