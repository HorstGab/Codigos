package controller;

import java.util.ArrayList;

import javax.swing.JInternalFrame;

import dao.DaoCliente;
import model.Model;
import model.ModelCliente;
import util.Observador;
import util.Param;
import view.ViewConsultarCliente;
import view.ViewManterCliente;

public class ControllerCliente implements Observador {
	
	private DaoCliente dao = new DaoCliente();	
	private ViewConsultarCliente viewConsultar = new ViewConsultarCliente(this);
	private ViewManterCliente viewManter = new ViewManterCliente(this);
	

	public ControllerCliente () {
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
		viewConsultar.atualizar(  (ModelCliente)model, dao.salvar( (ModelCliente)model ) );		
	}

	@Override
	public void remover(Model model) {
		viewConsultar.remover ( (ModelCliente)model, dao.remover( (ModelCliente)model ) );		
	}

	@Override
	public void fechar() {
		//viewConsultar.setVisible(false);			
	}

}
