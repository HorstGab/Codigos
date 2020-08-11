package model;

public class NumeroInt extends Node {

	private int valor;
	
	public NumeroInt (int valor) {
		//transforma o valor em string
		super(String.valueOf(valor));
		this.valor = valor;
	}
	
	@Override
	public double processa() {
		return this.valor;
	}
}
