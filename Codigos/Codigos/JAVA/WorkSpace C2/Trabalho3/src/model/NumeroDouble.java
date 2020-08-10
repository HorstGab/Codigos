package model;

public class NumeroDouble extends Node {

	private double valor;
	
	public NumeroDouble (double valor) {
		super (String.valueOf(valor));
		this.valor = valor;
	}
	
	@Override
	public double processa() {
		return this.valor;
	}

}
