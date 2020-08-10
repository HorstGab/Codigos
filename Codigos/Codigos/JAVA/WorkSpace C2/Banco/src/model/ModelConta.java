package model;

import java.util.ArrayList;

import dao.DaoCliente;
import dao.DaoMovimentacao;
import dao.DaoMovimentacao;
import util.Param;

public class ModelConta extends Model {
	
	protected int    idconta=-1;
	protected int    idcliente;
	protected int    numero;
	protected double saldo;
	protected String status;
	protected int    limite;
	
	// Vem da tabela Cliente
	protected ModelCliente cliente=null;
	
	@Override
	public int getId() {
		return this.idconta;
	}

	public int getIdconta() {
		return idconta;
	}

	public void setIdconta(int idconta) {
		this.idconta = idconta;
	}

	public int getIdcliente() {
		return idcliente;
	}

	public void setIdcliente(int idcliente) {
		this.idcliente = idcliente;
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}

	public double getSaldo() {
		return saldo;
	}

	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	public int getLimite() {
		return limite;
	}

	public void setLimite(int limite) {
		this.limite = limite;
	}

	public ModelCliente getCliente() {
		if (this.cliente==null) {
			DaoCliente dao = new DaoCliente();
			this.cliente = (ModelCliente)dao.consultaPorId(this.idcliente);
		}
		return this.cliente;
	}

	public ArrayList<Model> getMovimentacao() {
		DaoMovimentacao dao = new DaoMovimentacao();
		ArrayList<Param> params = new ArrayList<Param>();
		params.add( new Param ( "idconta", this.idconta ));
		return dao.consultar(params);
	}
	
	public void setCliente(ModelCliente cliente) {
		this.cliente = cliente;
	}
	
	public boolean sacar ( double valor ) {
		if ((saldo-valor+limite)>=0) {
			this.saldo -= valor;			
			return true;			
		}
		return false;
	}
	
	public void depositar ( double valor ) {
		this.saldo += valor;			
	}

	public String toString() {
		return this.numero + " " + this.saldo;
	}

}
